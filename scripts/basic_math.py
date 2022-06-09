import basic_math_clib as basic_math
from basic_math_clib import add, subtract

print(basic_math.__doc__)
print(help(basic_math))
print('=====')

print(add.__doc__)
print(f'Default: {add()}')
print(f'3 + 4 = {add(3, 4)}')
print(f'6 + 5 = {add(j=5, i=6)}')
print('=====')

print(subtract.__doc__)
print(f'Default: {subtract()}')
print(f'10 - 4 = {subtract(10, 4)}')
print(f'5 - 6 = {subtract(j=6, i=5)}')
print('=====')

print(f'The answer: {basic_math.the_answer}')