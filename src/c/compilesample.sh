clear 
clang -shared -undefined dynamic_lookup -lcblite -Wall -I ./include -L ./lib -rpath ./lib -o ./lib/libcbl_helper.so cbl_helper.c
clang -o out/main main.c -lcblite -rpath ./lib -Wall -I ./include -L ./lib