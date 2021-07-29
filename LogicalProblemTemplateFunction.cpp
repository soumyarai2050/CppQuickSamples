//
// Created by <> on DD/MM/YYYY.
// Purpose: <Explain the intent - Suitable for problem requiring a function template>
//

template <typename T>
T Func (T t)
{
    return t;
}

int TestFunc()
{
    int a = 5;
    a = Func(a);
    return a;
}

int main()
{
    TestFunc();
    return 0;
}