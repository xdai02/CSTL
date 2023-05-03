#include "test_wrapper.h"
#include "coop.h"
#include <assert.h>

void test_Character() {
    Character *c1 = Character_new('a');
    Character *c2 = Character_new('b');
    Character *c3 = Character_new('a');

    assert(Character_get(c1) == 'a');
    assert(Character_get(c2) == 'b');
    assert(Character_get(c3) == 'a');

    assert(Character_compare(c1, c2) < 0);
    assert(Character_compare(c2, c1) > 0);
    assert(Character_compare(c1, c3) == 0);

    assert(Character_equals(c1, c2) == false);
    assert(Character_equals(c2, c1) == false);
    assert(Character_equals(c1, c3) == true);

    Character_set(c1, 'b');
    Character_set(c2, 'a');
    Character_set(c3, 'b');

    assert(Character_get(c1) == 'b');
    assert(Character_get(c2) == 'a');
    assert(Character_get(c3) == 'b');

    Character_delete(c1);
    Character_delete(c2);
    Character_delete(c3);
}

void test_UnsignedCharacter() {
    UnsignedCharacter *uc1 = UnsignedCharacter_new('a');
    UnsignedCharacter *uc2 = UnsignedCharacter_new('b');
    UnsignedCharacter *uc3 = UnsignedCharacter_new('a');

    assert(UnsignedCharacter_get(uc1) == 'a');
    assert(UnsignedCharacter_get(uc2) == 'b');
    assert(UnsignedCharacter_get(uc3) == 'a');

    assert(UnsignedCharacter_compare(uc1, uc2) < 0);
    assert(UnsignedCharacter_compare(uc2, uc1) > 0);
    assert(UnsignedCharacter_compare(uc1, uc3) == 0);

    assert(UnsignedCharacter_equals(uc1, uc2) == false);
    assert(UnsignedCharacter_equals(uc2, uc1) == false);
    assert(UnsignedCharacter_equals(uc1, uc3) == true);

    UnsignedCharacter_set(uc1, 'b');
    UnsignedCharacter_set(uc2, 'a');
    UnsignedCharacter_set(uc3, 'b');

    assert(UnsignedCharacter_get(uc1) == 'b');
    assert(UnsignedCharacter_get(uc2) == 'a');
    assert(UnsignedCharacter_get(uc3) == 'b');

    UnsignedCharacter_delete(uc1);
    UnsignedCharacter_delete(uc2);
    UnsignedCharacter_delete(uc3);
}

void test_Short() {
    Short *s1 = Short_new(1);
    Short *s2 = Short_new(2);
    Short *s3 = Short_new(1);

    assert(Short_get(s1) == 1);
    assert(Short_get(s2) == 2);
    assert(Short_get(s3) == 1);

    assert(Short_compare(s1, s2) < 0);
    assert(Short_compare(s2, s1) > 0);
    assert(Short_compare(s1, s3) == 0);

    assert(Short_equals(s1, s2) == false);
    assert(Short_equals(s2, s1) == false);
    assert(Short_equals(s1, s3) == true);

    Short_set(s1, 2);
    Short_set(s2, 1);
    Short_set(s3, 2);

    assert(Short_get(s1) == 2);
    assert(Short_get(s2) == 1);
    assert(Short_get(s3) == 2);

    Short_delete(s1);
    Short_delete(s2);
    Short_delete(s3);
}

void test_UnsignedShort() {
    UnsignedShort *us1 = UnsignedShort_new(1);
    UnsignedShort *us2 = UnsignedShort_new(2);
    UnsignedShort *us3 = UnsignedShort_new(1);

    assert(UnsignedShort_get(us1) == 1);
    assert(UnsignedShort_get(us2) == 2);
    assert(UnsignedShort_get(us3) == 1);

    assert(UnsignedShort_compare(us1, us2) < 0);
    assert(UnsignedShort_compare(us2, us1) > 0);
    assert(UnsignedShort_compare(us1, us3) == 0);

    assert(UnsignedShort_equals(us1, us2) == false);
    assert(UnsignedShort_equals(us2, us1) == false);
    assert(UnsignedShort_equals(us1, us3) == true);

    UnsignedShort_set(us1, 2);
    UnsignedShort_set(us2, 1);
    UnsignedShort_set(us3, 2);

    assert(UnsignedShort_get(us1) == 2);
    assert(UnsignedShort_get(us2) == 1);
    assert(UnsignedShort_get(us3) == 2);

    UnsignedShort_delete(us1);
    UnsignedShort_delete(us2);
    UnsignedShort_delete(us3);
}

void test_Integer() {
    Integer *i1 = Integer_new(1);
    Integer *i2 = Integer_new(2);
    Integer *i3 = Integer_new(1);

    assert(Integer_get(i1) == 1);
    assert(Integer_get(i2) == 2);
    assert(Integer_get(i3) == 1);

    assert(Integer_compare(i1, i2) < 0);
    assert(Integer_compare(i2, i1) > 0);
    assert(Integer_compare(i1, i3) == 0);

    assert(Integer_equals(i1, i2) == false);
    assert(Integer_equals(i2, i1) == false);
    assert(Integer_equals(i1, i3) == true);

    Integer_set(i1, 2);
    Integer_set(i2, 1);
    Integer_set(i3, 2);

    assert(Integer_get(i1) == 2);
    assert(Integer_get(i2) == 1);
    assert(Integer_get(i3) == 2);

    Integer_delete(i1);
    Integer_delete(i2);
    Integer_delete(i3);
}

void test_UnsignedInteger() {
    UnsignedInteger *ui1 = UnsignedInteger_new(1);
    UnsignedInteger *ui2 = UnsignedInteger_new(2);
    UnsignedInteger *ui3 = UnsignedInteger_new(1);

    assert(UnsignedInteger_get(ui1) == 1);
    assert(UnsignedInteger_get(ui2) == 2);
    assert(UnsignedInteger_get(ui3) == 1);

    assert(UnsignedInteger_compare(ui1, ui2) < 0);
    assert(UnsignedInteger_compare(ui2, ui1) > 0);
    assert(UnsignedInteger_compare(ui1, ui3) == 0);

    assert(UnsignedInteger_equals(ui1, ui2) == false);
    assert(UnsignedInteger_equals(ui2, ui1) == false);
    assert(UnsignedInteger_equals(ui1, ui3) == true);

    UnsignedInteger_set(ui1, 2);
    UnsignedInteger_set(ui2, 1);
    UnsignedInteger_set(ui3, 2);

    assert(UnsignedInteger_get(ui1) == 2);
    assert(UnsignedInteger_get(ui2) == 1);
    assert(UnsignedInteger_get(ui3) == 2);

    UnsignedInteger_delete(ui1);
    UnsignedInteger_delete(ui2);
    UnsignedInteger_delete(ui3);
}

void test_Long() {
    Long *l1 = Long_new(1);
    Long *l2 = Long_new(2);
    Long *l3 = Long_new(1);

    assert(Long_get(l1) == 1);
    assert(Long_get(l2) == 2);
    assert(Long_get(l3) == 1);

    assert(Long_compare(l1, l2) < 0);
    assert(Long_compare(l2, l1) > 0);
    assert(Long_compare(l1, l3) == 0);

    assert(Long_equals(l1, l2) == false);
    assert(Long_equals(l2, l1) == false);
    assert(Long_equals(l1, l3) == true);

    Long_set(l1, 2);
    Long_set(l2, 1);
    Long_set(l3, 2);

    assert(Long_get(l1) == 2);
    assert(Long_get(l2) == 1);
    assert(Long_get(l3) == 2);

    Long_delete(l1);
    Long_delete(l2);
    Long_delete(l3);
}

void test_UnsignedLong() {
    UnsignedLong *ul1 = UnsignedLong_new(1);
    UnsignedLong *ul2 = UnsignedLong_new(2);
    UnsignedLong *ul3 = UnsignedLong_new(1);

    assert(UnsignedLong_get(ul1) == 1);
    assert(UnsignedLong_get(ul2) == 2);
    assert(UnsignedLong_get(ul3) == 1);

    assert(UnsignedLong_compare(ul1, ul2) < 0);
    assert(UnsignedLong_compare(ul2, ul1) > 0);
    assert(UnsignedLong_compare(ul1, ul3) == 0);

    assert(UnsignedLong_equals(ul1, ul2) == false);
    assert(UnsignedLong_equals(ul2, ul1) == false);
    assert(UnsignedLong_equals(ul1, ul3) == true);

    UnsignedLong_set(ul1, 2);
    UnsignedLong_set(ul2, 1);
    UnsignedLong_set(ul3, 2);

    assert(UnsignedLong_get(ul1) == 2);
    assert(UnsignedLong_get(ul2) == 1);
    assert(UnsignedLong_get(ul3) == 2);

    UnsignedLong_delete(ul1);
    UnsignedLong_delete(ul2);
    UnsignedLong_delete(ul3);
}

void test_Float() {
    Float *f1 = Float_new(1.1f);
    Float *f2 = Float_new(2.2f);
    Float *f3 = Float_new(1.1f);

    assert(Float_get(f1) == 1.1f);
    assert(Float_get(f2) == 2.2f);
    assert(Float_get(f3) == 1.1f);

    assert(Float_compare(f1, f2) < 0);
    assert(Float_compare(f2, f1) > 0);
    assert(Float_compare(f1, f3) == 0);

    assert(Float_equals(f1, f2) == false);
    assert(Float_equals(f2, f1) == false);
    assert(Float_equals(f1, f3) == true);

    Float_set(f1, 2.2f);
    Float_set(f2, 1.1f);
    Float_set(f3, 2.2f);

    assert(Float_equals(f1, f2) == false);
    assert(Float_equals(f2, f1) == false);
    assert(Float_equals(f1, f3) == true);

    Float_delete(f1);
    Float_delete(f2);
    Float_delete(f3);
}

void test_Double() {
    Double *d1 = Double_new(1.1);
    Double *d2 = Double_new(2.2);
    Double *d3 = Double_new(1.1);

    assert(Double_get(d1) == 1.1);
    assert(Double_get(d2) == 2.2);
    assert(Double_get(d3) == 1.1);

    assert(Double_compare(d1, d2) < 0);
    assert(Double_compare(d2, d1) > 0);
    assert(Double_compare(d1, d3) == 0);

    assert(Double_equals(d1, d2) == false);
    assert(Double_equals(d2, d1) == false);
    assert(Double_equals(d1, d3) == true);

    Double_set(d1, 2.2);
    Double_set(d2, 1.1);
    Double_set(d3, 2.2);

    assert(Double_equals(d1, d2) == false);
    assert(Double_equals(d2, d1) == false);
    assert(Double_equals(d1, d3) == true);

    Double_delete(d1);
    Double_delete(d2);
    Double_delete(d3);
}

void test_Boolean() {
    Boolean *b1 = Boolean_new(true);
    Boolean *b2 = Boolean_new(false);
    Boolean *b3 = Boolean_new(true);

    assert(Boolean_get(b1) == true);
    assert(Boolean_get(b2) == false);
    assert(Boolean_get(b3) == true);

    assert(Boolean_compare(b1, b2) > 0);
    assert(Boolean_compare(b2, b1) < 0);
    assert(Boolean_compare(b1, b3) == 0);

    assert(Boolean_equals(b1, b2) == false);
    assert(Boolean_equals(b2, b1) == false);
    assert(Boolean_equals(b1, b3) == true);

    Boolean_set(b1, false);
    Boolean_set(b2, true);
    Boolean_set(b3, false);

    assert(Boolean_equals(b1, b2) == false);
    assert(Boolean_equals(b2, b1) == false);
    assert(Boolean_equals(b1, b3) == true);

    Boolean_delete(b1);
    Boolean_delete(b2);
    Boolean_delete(b3);
}
