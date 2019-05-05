import PY6502
import sys

print(sys.argv[1])
M = PY6502.PY6502_memory(sys.argv[1])
print("memory object made")
cpu = PY6502.PY6502_core(M)
print("cpu object made")

while(not cpu.brk()):
    cpu.run()

M.dump()