import ctypes
lib = ctypes.CDLL('../../build/lib/libcbl_helper.so')

create=lib.create
create.argtypes=[ctypes.c_char_p]
create.restype = ctypes.c_int

r=create("Test String".encode('utf-8'))
print(r)