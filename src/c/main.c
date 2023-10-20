#include <stdio.h>
#include <cbl/CouchbaseLite.h>
#include <fleece/Fleece.h>
#include <time.h>
#include <inttypes.h>
#include <unistd.h>


int main(int argc, char** argv) {

  // Get the database (and create it if it doesn't exist)
  CBLError err;
  CBLDatabase* database = CBLDatabase_Open(FLSTR("mydb"), NULL, &err);
  if(!database) {
      // Error handling.  For brevity, this is truncated in the rest of the snippet
      // and omitted in other doc code snippets
      fprintf(stderr, "Error opening database (%d / %d)\n", err.domain, err.code);
      FLSliceResult msg = CBLError_Message(&err);
      fprintf(stderr, "%.*s\n", (int)msg.size, (const char *)msg.buf);
      FLSliceResult_Release(msg);
      return 1;
  }

  // Create a new document (i.e. a record) in the database
  CBLDocument* mutableDoc = CBLDocument_Create();

  FLMutableDict properties = CBLDocument_MutableProperties(mutableDoc);
  FLMutableDict_SetFloat(properties, FLSTR("version"), 3.0f);
  FLMutableDict_SetString(properties, FLSTR("language"), FLSTR("C"));

  // Save it to the database
  if(!CBLDatabase_SaveDocument(database, mutableDoc, &err)) {
      // Failed to save, do error handling as above
      return 1;
  }

  // Since we will release the document, make a copy of the ID since it
  // is an internal pointer.  Whenever we create or get an FLSliceResult
  // or FLStringResult we will need to free it later too!
  FLStringResult id = FLSlice_Copy(CBLDocument_ID(mutableDoc));
  CBLDocument_Release(mutableDoc);

  // Note const here, means readonly
  const CBLDocument* docAgain = CBLDatabase_GetDocument(database, FLSliceResult_AsSlice(id), &err);
  if(!docAgain) {
      // Failed to retrieve, do error handling as above.  NOTE: error code 0 simply means
      // the document does not exist.
      return 1;
  }

  // No copy this time, so no release later (notice it is not FLStringResult this time)
  FLString retrievedID = CBLDocument_ID(docAgain);
  FLDict retrievedProperties = CBLDocument_Properties(docAgain);
  FLString retrievedLanguage = FLValue_AsString(FLDict_Get(retrievedProperties, FLSTR("language")));
  float version = FLValue_AsFloat(FLDict_Get(retrievedProperties, FLSTR("version")));
  printf("Document ID = %.*s\n", (int)retrievedID.size, (const char *)retrievedID.buf);
  printf("Language = %.*s\n", (int)retrievedLanguage.size, (const char *)retrievedLanguage.buf);
  printf("Version = %f\n", version);

  // Close database. No error handling for brevity
  CBLDatabase_Close(database, &err);

  // Release resources
  CBLDocument_Release(docAgain);
  FLSliceResult_Release(id);
  CBLDatabase_Release(database);
  return 0;
}