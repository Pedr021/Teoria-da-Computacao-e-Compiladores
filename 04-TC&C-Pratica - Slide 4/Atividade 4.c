result = set([(0, 1)])
for n in range(1, i + 1):
new_elements = [(j, n + 1) for j in range(n + 1)]
result.update(new_elements)
return result
i = int(input("Informe o valor de i: "))
result = MQ(i)
print("Conjunto MQ para i =", i, ":", result)