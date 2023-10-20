 #Setup Scripts for the library
curl https://packages.couchbase.com/releases/couchbase-lite-c/3.1.1/couchbase-lite-c-enterprise-3.1.1-macos.zip --output ./couchbase-lite-c-enterprise-3.1.1-macos.zip
unzip ./couchbase-lite-c-enterprise-3.1.1-macos.zip 
mkdir ./lib
mkdir ./include
mkdir ./out
cp -R ./libcblite-3.1.1/include/* ./include/
cp -R ./libcblite-3.1.1/lib/* ./lib/
rm -Rf ./libcblite-3.1.1
rm couchbase-lite-c-enterprise-3.1.1-macos.zip