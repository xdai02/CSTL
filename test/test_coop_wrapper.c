#include "test_coop_wrapper.h"
#include "coop.h"
#include <assert.h>

void test_Character() {
    Character *c1 = Character_new('a');
    Character *c2 = Character_new('b');
    Character *c3 = Character_new('a');

    assert(Character_valueOf(c1) == 'a');
    assert(Character_valueOf(c2) == 'b');
    assert(Character_valueOf(c3) == 'a');

    assert(Character_compare(c1, c2) < 0);
    assert(Character_compare(c2, c1) > 0);
    assert(Character_compare(c1, c3) == 0);

    assert(Character_equals(c1, c2) == false);
    assert(Character_equals(c2, c1) == false);
    assert(Character_equals(c1, c3) == true);

    Character_delete(c1);
    Character_delete(c2);
    Character_delete(c3);
}

void test_UnsignedCharacter() {
    UnsignedCharacter *uc1 = UnsignedCharacter_new('a');
    UnsignedCharacter *uc2 = UnsignedCharacter_new('b');
    UnsignedCharacter *uc3 = UnsignedCharacter_new('a');

    assert(UnsignedCharacter_valueOf(uc1) == 'a');
    assert(UnsignedCharacter_valueOf(uc2) == 'b');
    assert(UnsignedCharacter_valueOf(uc3) == 'a');

    assert(UnsignedCharacter_compare(uc1, uc2) < 0);
    assert(UnsignedCharacter_compare(uc2, uc1) > 0);
    assert(UnsignedCharacter_compare(uc1, uc3) == 0);

    assert(UnsignedCharacter_equals(uc1, uc2) == false);
    assert(UnsignedCharacter_equals(uc2, uc1) == false);
    assert(UnsignedCharacter_equals(uc1, uc3) == true);

    UnsignedCharacter_delete(uc1);
    UnsignedCharacter_delete(uc2);
    UnsignedCharacter_delete(uc3);
}

void test_Short() {
    Short *s1 = Short_new(1);
    Short *s2 = Short_new(2);
    Short *s3 = Short_new(1);

    assert(Short_valueOf(s1) == 1);
    assert(Short_valueOf(s2) == 2);
    assert(Short_valueOf(s3) == 1);

    assert(Short_compare(s1, s2) < 0);
    assert(Short_compare(s2, s1) > 0);
    assert(Short_compare(s1, s3) == 0);

    assert(Short_equals(s1, s2) == false);
    assert(Short_equals(s2, s1) == false);
    assert(Short_equals(s1, s3) == true);

    Short_delete(s1);
    Short_delete(s2);
    Short_delete(s3);
}

void test_UnsignedShort() {
    UnsignedShort *us1 = UnsignedShort_new(1);
    UnsignedShort *us2 = UnsignedShort_new(2);
    UnsignedShort *us3 = UnsignedShort_new(1);

    assert(UnsignedShort_valueOf(us1) == 1);
    assert(UnsignedShort_valueOf(us2) == 2);
    assert(UnsignedShort_valueOf(us3) == 1);

    assert(UnsignedShort_compare(us1, us2) < 0);
    assert(UnsignedShort_compare(us2, us1) > 0);
    assert(UnsignedShort_compare(us1, us3) == 0);

    assert(UnsignedShort_equals(us1, us2) == false);
    assert(UnsignedShort_equals(us2, us1) == false);
    assert(UnsignedShort_equals(us1, us3) == true);

    UnsignedShort_delete(us1);
    UnsignedShort_delete(us2);
    UnsignedShort_delete(us3);
}

void test_Integer() {
    Integer *i1 = Integer_new(1);
    Integer *i2 = Integer_new(2);
    Integer *i3 = Integer_new(1);

    assert(Integer_valueOf(i1) == 1);
    assert(Integer_valueOf(i2) == 2);
    assert(Integer_valueOf(i3) == 1);

    assert(Integer_compare(i1, i2) < 0);
    assert(Integer_compare(i2, i1) > 0);
    assert(Integer_compare(i1, i3) == 0);

    assert(Integer_equals(i1, i2) == false);
    assert(Integer_equals(i2, i1) == false);
    assert(Integer_equals(i1, i3) == true);

    Integer_delete(i1);
    Integer_delete(i2);
    Integer_delete(i3);
}

void test_UnsignedInteger() {
    UnsignedInteger *ui1 = UnsignedInteger_new(1);
    UnsignedInteger *ui2 = UnsignedInteger_new(2);
    UnsignedInteger *ui3 = UnsignedInteger_new(1);

    assert(UnsignedInteger_valueOf(ui1) == 1);
    assert(UnsignedInteger_valueOf(ui2) == 2);
    assert(UnsignedInteger_valueOf(ui3) == 1);

    assert(UnsignedInteger_compare(ui1, ui2) < 0);
    assert(UnsignedInteger_compare(ui2, ui1) > 0);
    assert(UnsignedInteger_compare(ui1, ui3) == 0);

    assert(UnsignedInteger_equals(ui1, ui2) == false);
    assert(UnsignedInteger_equals(ui2, ui1) == false);
    assert(UnsignedInteger_equals(ui1, ui3) == true);

    UnsignedInteger_delete(ui1);
    UnsignedInteger_delete(ui2);
    UnsignedInteger_delete(ui3);
}

void test_Long() {
    Long *l1 = Long_new(1);
    Long *l2 = Long_new(2);
    Long *l3 = Long_new(1);

    assert(Long_valueOf(l1) == 1);
    assert(Long_valueOf(l2) == 2);
    assert(Long_valueOf(l3) == 1);

    assert(Long_compare(l1, l2) < 0);
    assert(Long_compare(l2, l1) > 0);
    assert(Long_compare(l1, l3) == 0);

    assert(Long_equals(l1, l2) == false);
    assert(Long_equals(l2, l1) == false);
    assert(Long_equals(l1, l3) == true);

    Long_delete(l1);
    Long_delete(l2);
    Long_delete(l3);
}

void test_UnsignedLong() {
    UnsignedLong *ul1 = UnsignedLong_new(1);
    UnsignedLong *ul2 = UnsignedLong_new(2);
    UnsignedLong *ul3 = UnsignedLong_new(1);

    assert(UnsignedLong_valueOf(ul1) == 1);
    assert(UnsignedLong_valueOf(ul2) == 2);
    assert(UnsignedLong_valueOf(ul3) == 1);

    assert(UnsignedLong_compare(ul1, ul2) < 0);
    assert(UnsignedLong_compare(ul2, ul1) > 0);
    assert(UnsignedLong_compare(ul1, ul3) == 0);

    assert(UnsignedLong_equals(ul1, ul2) == false);
    assert(UnsignedLong_equals(ul2, ul1) == false);
    assert(UnsignedLong_equals(ul1, ul3) == true);

    UnsignedLong_delete(ul1);
    UnsignedLong_delete(ul2);
    UnsignedLong_delete(ul3);
}

void test_Float() {
    Float *f1 = Float_new(1.1f);
    Float *f2 = Float_new(2.2f);
    Float *f3 = Float_new(1.1f);

    assert(Float_valueOf(f1) == 1.1f);
    assert(Float_valueOf(f2) == 2.2f);
    assert(Float_valueOf(f3) == 1.1f);

    assert(Float_compare(f1, f2) < 0);
    assert(Float_compare(f2, f1) > 0);
    assert(Float_compare(f1, f3) == 0);

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

    assert(Double_valueOf(d1) == 1.1);
    assert(Double_valueOf(d2) == 2.2);
    assert(Double_valueOf(d3) == 1.1);

    assert(Double_compare(d1, d2) < 0);
    assert(Double_compare(d2, d1) > 0);
    assert(Double_compare(d1, d3) == 0);

    assert(Double_equals(d1, d2) == false);
    assert(Double_equals(d2, d1) == false);
    assert(Double_equals(d1, d3) == true);

    Double_delete(d1);
    Double_delete(d2);
    Double_delete(d3);
}

void test_LongDouble() {
    LongDouble *ld1 = LongDouble_new(1.1L);
    LongDouble *ld2 = LongDouble_new(2.2L);
    LongDouble *ld3 = LongDouble_new(1.1L);

    assert(LongDouble_valueOf(ld1) == 1.1L);
    assert(LongDouble_valueOf(ld2) == 2.2L);
    assert(LongDouble_valueOf(ld3) == 1.1L);

    assert(LongDouble_compare(ld1, ld2) < 0);
    assert(LongDouble_compare(ld2, ld1) > 0);
    assert(LongDouble_compare(ld1, ld3) == 0);

    assert(LongDouble_equals(ld1, ld2) == false);
    assert(LongDouble_equals(ld2, ld1) == false);
    assert(LongDouble_equals(ld1, ld3) == true);

    LongDouble_delete(ld1);
    LongDouble_delete(ld2);
    LongDouble_delete(ld3);
}

void test_Boolean() {
    Boolean *b1 = Boolean_new(true);
    Boolean *b2 = Boolean_new(false);
    Boolean *b3 = Boolean_new(true);

    assert(Boolean_valueOf(b1) == true);
    assert(Boolean_valueOf(b2) == false);
    assert(Boolean_valueOf(b3) == true);

    assert(Boolean_compare(b1, b2) > 0);
    assert(Boolean_compare(b2, b1) < 0);
    assert(Boolean_compare(b1, b3) == 0);

    assert(Boolean_equals(b1, b2) == false);
    assert(Boolean_equals(b2, b1) == false);
    assert(Boolean_equals(b1, b3) == true);

    Boolean_delete(b1);
    Boolean_delete(b2);
    Boolean_delete(b3);
}
