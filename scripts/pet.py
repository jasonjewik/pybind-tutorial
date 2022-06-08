from pet_clib import Pet

# Note that we have to use get_name/set_name because those are the bindings
# for Pet's getName and setName methods.

# However, we can use .age for getting/setting the Pet's age because we bound
# Pet's getAge and setAge methods to Python's property getter/setter.

p = Pet('Marcy', 3)
print(f'Created a pet named {p.get_name()} who is {p.age} years old')
p.set_name('Belle')
print(f'Changed pet\'s name to {p.get_name()} who is {p.age} years old')
p.age = 4
print(f'{p.get_name()} is now {p.age} years old')