#include <stdio.h>

typedef struct
{
    char name[50];
    int age;
    float height;
    int health;
} Person_t;

int getHealth(Person_t *p)
{
    return p->health;
}

int main()
{
    Person_t person = {"Jane Doe", 20, 155, 0};
    int x = 0;

    // 関数呼び出し
    // -O0で最適化しない場合、callで関数が呼ばれる
    // -O3の最適化の場合、結果のxは、後で変更されるのでこのコードはなくなる。
    for (int i = 0; i < 1000000; i++)
    {
        x = getHealth(&person);
    }

    // -O0で最適化しない場合、callがないので、パフォーマンスがよい。
    // -O3の最適化の場合、xは値が変わらないので、
    // movq $0 $rax のように、ハードコーディングされる。
    // この計算をコンパイル時に済ませてしまうことを**「定数伝播（Constant Propagation）」**と呼ぶ
    for (int i = 0; i < 1000000; i++)
    {
        x = person.health;
    }

    printf("Final x: %d\n", x);

    return 0;
}