import std.stdio;

void HelloWorldFromAnotherFunction(string str);

void main() {
    HelloWorldFromAnotherFunction("Hello World!");
}

void HelloWorldFromAnotherFunction(string str)
{
    writeln(str);
}
