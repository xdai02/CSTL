#include "test_cino_array.h"

void test_array_create() {
    array_t *arr1 = array_create(sizeof(int));
    assert(arr1);
    for (int i = 0; i < 100; i++) {
        array_append(arr1, &i);
    }
    assert(array_size(arr1) == 100);
    for (int i = 0; i < 100; i++) {
        printf("i = %d\n", *(int *)array_get(arr1, i));
        assert(*(int *)array_get(arr1, i) == i);
    }
    array_destroy(arr1);

    array_t *arr2 = array_create(sizeof(char));
    assert(arr2);
    for (char i = 'A'; i <= 'Z'; i++) {
        array_append(arr2, &i);
    }
    assert(array_size(arr2) == 26);
    for (char i = 'A'; i <= 'Z'; i++) {
        assert(*(char *)array_get(arr2, i - 'A') == i);
    }
    array_destroy(arr2);

    struct test_t {
        int val;
    };

    array_t *arr3 = array_create(sizeof(struct test_t));
    struct test_t t1 = {123};
    struct test_t t2 = {987};
    array_append(arr3, &t1);
    array_append(arr3, &t2);
    assert(array_size(arr3) == 2);
    assert(((struct test_t *)array_get(arr3, 1))->val == 987);
    assert(((struct test_t *)array_get(arr3, 0))->val == 123);
    array_destroy(arr3);

    array_t *arr4 = array_create(sizeof(struct test_t));
    assert(arr4);
    struct test_t *t3 = (struct test_t *)malloc(sizeof(struct test_t));
    struct test_t *t4 = (struct test_t *)malloc(sizeof(struct test_t));
    struct test_t *t5 = (struct test_t *)malloc(sizeof(struct test_t));
    t3->val = 789;
    t4->val = 321;
    t5->val = 567;
    array_append(arr4, t3);
    array_append(arr4, t4);
    array_append(arr4, t5);
    assert(array_size(arr4) == 3);
    assert(((struct test_t *)array_get(arr4, 2))->val == 567);
    assert(((struct test_t *)array_get(arr4, 1))->val == 321);
    assert(((struct test_t *)array_get(arr4, 0))->val == 789);
    free(t3);
    free(t4);
    free(t5);
    array_destroy(arr4);

    struct student_t {
        char *name;
        int age;
    };

    array_t *arr5 = array_create(sizeof(struct student_t));
    assert(arr5);
    for (int i = 0; i < 1000; i++) {
        struct student_t *s = (struct student_t *)malloc(sizeof(struct student_t));
        s->name = (char *)malloc(sizeof(char) * 32);
        snprintf(s->name, 32, "name-%d", i);
        s->age = i;
        array_append(arr5, s);
    }
    assert(array_size(arr5) == 1000);
    for (int i = 0; i < 1000; i++) {
        char name[32] = {0};
        snprintf(name, sizeof(name), "name-%d", i);
        struct student_t *s = (struct student_t *)array_get(arr5, i);
        assert(strncmp(s->name, name, sizeof(name)) == 0);
        assert(s->age == i);
        free(s->name);
        free(s);
    }
    array_destroy(arr5);
}