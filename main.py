import sys
sys.path.append("build/shared")
from example import add

def main():
    print(add.__doc__)
    print(f'Default: {add()}')
    print(f'3 + 4 = {add(3, 4)}')
    print(f'6 + 5 = {add(j=5, i=6)}')

if __name__ == '__main__':
    main()