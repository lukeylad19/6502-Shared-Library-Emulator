import ctypes

lib = ctypes.cdll.LoadLibrary('lib6502.so')

class PY6502_core(object):
    def __init__(self,mem):
        lib.M6502_core_new.argtypes = [ctypes.c_void_p] #constructor
        lib.M6502_core_new.restype = ctypes.c_void_p

        lib.M6502_core_brk.argtypes = [ctypes.c_void_p] #_brk
        lib.M6502_core_brk.restype = ctypes.c_bool

        lib.M6502_core_run.argtypes = [ctypes.c_void_p]
        lib.M6502_core_run.restype = ctypes.c_void_p

        lib.M6502_core_reset.argtypes = [ctypes.c_void_p]
        lib.M6502_core_reset.restype = ctypes.c_void_p

        lib.M6502_core_irq.argtypes = [ctypes.c_void_p]
        lib.M6502_core_irq.restype = ctypes.c_void_p

        lib.M6502_core_nmi.argtypes = [ctypes.c_void_p]
        lib.M6502_core_nmi.restype = ctypes.c_void_p

        self.obj = lib.M6502_core_new(mem)
    
    def brk(self):
        lib.M6502_core_brk(self.obj)

    def run(self):
        lib.M6502_core_run(self.obj)

    def reset(self):
        lib.M6502_core_reset(self.obj)
    
    def nmi(self):
        lib.M6502_core_nmi(self.obj)
    
    def irq(self):
        lib.M6502_core_irq(self.obj)

class PY6502_memory(object):
    def __init__(self,rom):
        lib.M6502_memory_new.argtypes = [ctypes.c_char_p]
        lib.M6502_memory_new.restype = ctypes.c_void_p

        lib.M6502_memory_read.argtypes = [ctypes.c_void_p,ctypes.c_uint16]
        lib.M6502_memory_read.restype = ctypes.c_uint8

        lib.M6502_memory_readWord.argtypes = [ctypes.c_void_p, ctypes.c_uint16]
        lib.M6502_memory_readWord.restype = ctypes.c_uint16

        lib.M6502_memory_write.argtypes = [ctypes.c_void_p, ctypes.c_uint16, ctypes.c_uint8]
        lib.M6502_memory_write.restype = ctypes.c_void_p

        lib.M6502_memory_dump.argtypes = [ctypes.c_void_p]
        lib.M6502_memory_dump.restype = ctypes.c_void_p

        self.obj = lib.M6502_memory_new(rom)

    def read(self,addr):
        return lib.M6502_memory_read(addr)
    
    def readWord(self,addr):
        return lib.M6502_memory_readWord(addr)

    def write(self,addr,data):
        lib.M6502_memory_write(addr,data)
    
    def dump(self):
        lib.M6502_memory_dump()