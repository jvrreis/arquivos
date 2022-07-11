from ctypes import sizeof
from io import SEEK_END
from shutil import which
import struct
import sys


registroCEP = struct.Struct("72s72s72s72s2s8s2s")
ufColumn = 5


with open("cep_ordenado.dat","rb") as f:

    f.seek(0, 2)
    tb =f.tell()
    tr = tb // registroCEP.size
    inicio = 0
    fim = tr-1
    qt = 0
    while(inicio<=fim):
        meio = (inicio + fim) // 2
        f.seek(meio * registroCEP.size)
        line = f.read(registroCEP.size)
        record = registroCEP.unpack(line)
        qt += 1
        if sys.argv[1] >  record[ufColumn].decode('latin1'):
            inicio = meio
        elif sys.argv[1] < record[ufColumn].decode('latin1'):
            fim = meio
        elif sys.argv[1] == record[ufColumn].decode('latin1'):
            print(f"O endereco eh: {line}")
            print(f"A busca foi feita {qt} vezes")
            break
