def MQ(i):
if i == 0:
return set([(0, 1)])
else:
previous_MQ = MQ(i - 1)
new_elements = [(j, i + 1) for j in range(i + 1)]
return previous_MQ.union(new_elements)
i = int(input("Informe o valor de i: "))
result = MQ(i)
print("Conjunto MQ para i =", i, ":", result)