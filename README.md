printf is the C language function to do formatted printing. 

printf("xyz") prints: xyz

For special characters, a backlash is needed in front of it.
To print a \ you need to type \\. To print a ", you need to type \".

The real power of printf is when we are printing the contents of variables. 

int age;
age = 25;
printf("I am %d years old\n", age);

