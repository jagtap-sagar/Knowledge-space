
// How do I find the name of the calling function

void foo(const char* str = __builtin_FUNCTION()){
    std::printf("called by %s\n", str);
}

int main()
{
    foo();
    #if 0
    cout<<"Hello World";
   #endif 
    return 0;
}
