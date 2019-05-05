import PY6502
import sys
import ctypes

print(sys.argv[1])
rom =sys.argv[1].encode('utf-8')
M = PY6502.PY6502_memory(ctypes.create_string_buffer(rom))
print("memory object made")
cpu = PY6502.PY6502_core(M)
print("cpu object made")

while(not cpu.brk()):
    cpu.run()

M.dump()