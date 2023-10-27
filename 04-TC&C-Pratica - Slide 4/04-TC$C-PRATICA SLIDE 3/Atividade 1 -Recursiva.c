//Versão Recursiva

def f(n):
if n % 2 == 0:
return -n // 2
else:
return n // 2 + 1
def print_f_series(limite, i=0):
if i > limite:
return
result = f(i)
print(f"[{i}, {result}], ", end="")
print_f_series(limite, i + 1)
limite = int(input("Informe o limite: "))
print_f_series(limite)
