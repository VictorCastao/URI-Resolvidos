valor = float(input())
notasdiv = (100, 50, 20, 10, 5, 2)
moedasdiv = (1, 0.50, 0.25, 0.10, 0.05, 0.01)
print('NOTAS:')
for tipo in notasdiv:
    qtde = 0
    while valor >= tipo:
        valor -= tipo
        valor = round(valor, 2)
        qtde += 1
    print('{} nota(s) de R$ {:.2f}'.format(qtde, tipo))
print('MOEDAS:')
for tipo2 in moedasdiv:
    qtde2 = 0
    while valor >= tipo2:
        valor -= tipo2
        valor = round(valor, 2)
        qtde2 += 1
    print('{} moeda(s) de R$ {:.2f}'.format(qtde2, tipo2))

