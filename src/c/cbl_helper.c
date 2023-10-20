#include <stdio.h>
#include <cbl/CouchbaseLite.h>
#include <fleece/Fleece.h>

CBLDatabase *initDB(CBLDatabase *database)
{
    // Get the database (and create it if it doesn't exist)
    CBLError err;
    database = CBLDatabase_Open(FLSTR("mydb"), NULL, &err);
    if (!database)
    {
        // Error handling.  For brevity, this is truncated in the rest of the snippet
        // and omitted in other doc code snippets
        fprintf(stderr, "Error opening database (%d / %d)\n", err.domain, err.code);
        FLSliceResult msg = CBLError_Message(&err);
        fprintf(stderr, "%.*s\n", (int)msg.size, (const char *)msg.buf);
        FLSliceResult_Release(msg);
        return NULL;
    }
    return database;
}

int create(char *value)
{
    CBLDatabase *database;
    database=initDB(database);
    if (database!=NULL)
    {
        CBLError err;
        printf("Creating Record: %s", value);
        // Create a new document (i.e. a record) in the database
        CBLDocument *mutableDoc = CBLDocument_Create();

        FLMutableDict properties = CBLDocument_MutableProperties(mutableDoc);
        FLMutableDict_SetFloat(properties, FLSTR("version"), 3.0f);
        FLMutableDict_SetString(properties, FLSTR("language"), FLSTR("C"));

        // Save it to the database
        if (!CBLDatabase_SaveDocument(database, mutableDoc, &err))
        {
            // Failed to save, do error handling as above
            printf("%d", err.code);
            return -1;
        }
        return 1;
    }
    return 0;
}

int read(char *id)
{
    printf("Getting: %s", id);
    return 1;
}

int upsert(char *id, char *value)
{
    printf("Upserting: %s Record: %s", id, value);
    return 1;
}

int delete(char *id)
{
    printf("deleting: %s", id);
    return 1;
}