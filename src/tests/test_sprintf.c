#include "testing.h"

START_TEST(one_char) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'H';
  char *pattern = "This is ch = %c.";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'e';
  char *pattern = "This is ch = %-5c.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  char ch = '-';
  char *pattern = "This is nevazhno dlya ch = %+c.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_flag_space) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'l';
  char *pattern = "% c proverka probela!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'b';
  char *pattern = "%#c";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  char ch = '6';
  char *pattern = "%06c";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  char ch = '@';
  char *pattern = "%10c";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_star_width) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'y';
  int width = 4;
  char *pattern = "%*c - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, ch),
                   sprintf(buff2, pattern, width, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'x';
  char *pattern = "%.7c";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_char_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'z';
  int accuracy = 3;
  char *pattern = "%.*c";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, ch),
                   sprintf(buff2, pattern, accuracy, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_char_many_flags) {
  char buff1[2048];
  char buff2[2048];
  char ch1 = 'Y';
  char ch2 = 'w';
  char ch3 = '\0';
  char ch4 = '\n';
  char ch5 = '0';
  char ch6 = 'c';
  char ch7 = 'z';
  char ch8 = '#';
  char *pattern = "(%c)-(%-10c)-(%+c)-(% c)-(%#c)-(%0c)-(%2c)-(%.4c)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch1, ch2, ch3, ch4, ch5, ch6,
                               ch7, ch8, ch1, ch2),
                   sprintf(buff2, pattern, ch1, ch2, ch3, ch4, ch5, ch6, ch7,
                           ch8, ch1, ch2));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int) {
  char buff1[2048];
  char buff2[2048];
  int dec = 666;
  char *pattern = "%d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "%-10d - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Here you can see plus flag realization: %+d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_flag_space) {
  char buff1[2048];
  char buff2[2048];
  int dec = 4567;
  char *pattern = "Space flag % d - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  int dec = 7890;
  char *pattern = " hash version %#d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Zero flag for int %0d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = 115;
  char *pattern = "%10d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_star_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = -6782;
  int width = 4;
  char *pattern = "%*d - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, dec),
                   sprintf(buff2, pattern, width, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = 33346;
  char *pattern = "%.8d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = -412;
  int accuracy = 7;
  char *pattern = "%.*d";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, dec),
                   sprintf(buff2, pattern, accuracy, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_short_length) {
  char buff1[2048];
  char buff2[2048];
  short int dec = 15;
  char *pattern = "%hd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_long_length) {
  char buff1[2048];
  char buff2[2048];
  long int dec = 50000;
  char *pattern = "%ld";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_int_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long long int dec = 385868558;
  char *pattern = "%Ld";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_int_many_flags) {
  char buff1[2048];
  char buff2[2048];
  int dec1 = -911;
  int dec2 = 111;
  int dec3 = 0;
  int dec4 = -32767;
  int dec5 = 32767;
  int dec6 = 544;
  int dec7 = 55;
  int dec8 = -900;
  short int dec9 = 15;
  long int dec10 = 50000;
  long long int dec11 = 385868558;

  char *pattern =
      "(%d)-(%-10d)-(%+d)-(% d)-(%#d)-(%0d)-(%2d)-(%.4d)-(%hd)-(%ld)-(%Ld)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec1, dec2, dec3, dec4, dec5,
                               dec6, dec7, dec8, dec9, dec10, dec11),
                   sprintf(buff2, pattern, dec1, dec2, dec3, dec4, dec5, dec6,
                           dec7, dec8, dec9, dec10, dec11));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float) {
  char buff1[2048];
  char buff2[2048];
  float fl = 6.666;
  char *pattern = "%f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  float fl = -911.6557;
  char *pattern = "%-2f gkdbjgjhkd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  float fl = -66.34555;
  char *pattern = "Here you can see plus flag realization: %+f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_flag_space) {
  char buff1[2048];
  char buff2[2048];
  float fl = 783.0;
  char *pattern = "Space flag % f - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  float fl = 78.777;
  char *pattern = " hash version %#f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  float fl = -66.456;
  char *pattern = "Zero flag for int %06f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  float fl = 1.111111;
  char *pattern = "%4f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_star_width) {
  char buff1[2048];
  char buff2[2048];
  float fl = 12345.6640;
  int width = 4;
  char *pattern = "%*f - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, fl),
                   sprintf(buff2, pattern, width, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  float fl = 666.333333;
  char *pattern = "%.3f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  float fl = 4.4;
  int accuracy = 7;
  char *pattern = "%.*f";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, fl),
                   sprintf(buff2, pattern, accuracy, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_long_length) {
  char buff1[2048];
  char buff2[2048];
  double fl = 345.333215;
  char *pattern = "%lf";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_float_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long double fl = 385868.25254543;
  char *pattern = "%Lf";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_float_many_flags) {
  char buff1[2048];
  char buff2[2048];
  float fl1 = -911.11;
  float fl2 = 111.0;
  float fl3 = 0;
  float fl4 = -32767.543645;
  float fl5 = 32767.11111;
  float fl6 = 544.22222;
  float fl7 = 55.54300;
  float fl8 = -900.0000;
  double fl9 = 0.56789;
  long double fl10 = 63739.8765678;
  char *pattern =
      "(%f)-(%-5f)-(%+f)-(% f)-(%#f)-(%7f)-(%2f)-(%.4f)-(%lf)-(%Lf)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl1, fl2, fl3, fl4, fl5, fl6,
                               fl7, fl8, fl9, fl10),
                   sprintf(buff2, pattern, fl1, fl2, fl3, fl4, fl5, fl6, fl7,
                           fl8, fl9, fl10));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 0;
  char *pattern = "%u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 10000;
  char *pattern = "%-10u - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 1;
  char *pattern = "Here you can see plus flag realization: %+u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_flag_space) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 4567;
  char *pattern = "Space flag % u - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 7890;
  char *pattern = " hash version %#u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 9110;
  char *pattern = "Zero flag for int %0u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 15000;
  char *pattern = "%10u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_star_width) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 6782;
  int width = 2;
  char *pattern = "%*u - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, dec),
                   sprintf(buff2, pattern, width, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 6406;
  char *pattern = "%.8u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 412;
  int accuracy = 3;
  char *pattern = "%.*u";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, dec),
                   sprintf(buff2, pattern, accuracy, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_short_length) {
  char buff1[2048];
  char buff2[2048];
  unsigned short int dec = 1;
  char *pattern = "%hu";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_long_length) {
  char buff1[2048];
  char buff2[2048];
  unsigned long int dec = 675433;
  char *pattern = "%lu";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_Uint_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  unsigned long long int dec = 100000000;
  char *pattern = "%Lu";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_Uint_many_flags) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec1 = 911;
  unsigned int dec2 = 111;
  unsigned int dec3 = 0;
  unsigned int dec4 = 32767;
  unsigned int dec5 = 777;
  unsigned int dec6 = 544;
  unsigned int dec7 = 55;
  unsigned int dec8 = 900;
  unsigned short int dec9 = 100;
  unsigned long int dec10 = 84838;
  unsigned long long int dec11 = 6574839264;
  char *pattern =
      "(%u)-(%-10u)-(%+u)-(% u)-(%#u)-(%0u)-(%2u)-(%.4u)-(%hu)-(%lu)-(%Lu)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec1, dec2, dec3, dec4, dec5,
                               dec6, dec7, dec8, dec9, dec10, dec11),
                   sprintf(buff2, pattern, dec1, dec2, dec3, dec4, dec5, dec6,
                           dec7, dec8, dec9, dec10, dec11));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal) {
  char buff1[2048];
  char buff2[2048];
  int dec = 666;
  char *pattern = "%o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "%-10o - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Here you can see plus flag realization: %+o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_flag_space) {
  char buff1[2048];
  char buff2[2048];
  int dec = 4567;
  char *pattern = "Space flag % o - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  int dec = 7890;
  char *pattern = " hash version %#o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Zero flag for int %0o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = 115;
  char *pattern = "%10o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_star_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = -6782;
  int width = 4;
  char *pattern = "%*o - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, dec),
                   sprintf(buff2, pattern, width, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = 33346;
  char *pattern = "%.8o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = -412;
  int accuracy = 7;
  char *pattern = "%.*o";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, dec),
                   sprintf(buff2, pattern, accuracy, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_short_length) {
  char buff1[2048];
  char buff2[2048];
  short int dec = 1;
  char *pattern = "%ho";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_long_length) {
  char buff1[2048];
  char buff2[2048];
  long int dec = 675433;
  char *pattern = "%lo";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_octal_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long long int dec = 100000000;
  char *pattern = "%Lo";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_octal_many_flags) {
  char buff1[2048];
  char buff2[2048];
  int dec1 = -911;
  int dec2 = 111;
  int dec3 = 0;
  int dec4 = -32767;
  int dec5 = 32767;
  int dec6 = 544;
  int dec7 = 55;
  int dec8 = -900;
  short int dec9 = 0;
  long int dec10 = -454467;
  long long int dec11 = -5678909765;

  char *pattern =
      "(%o)-(%-10o)-(%+o)-(% o)-(%#o)-(%0o)-(%2o)-(%.4o)-(%ho)-(%lo)-(%Lo)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec1, dec2, dec3, dec4, dec5,
                               dec6, dec7, dec8, dec9, dec10, dec11),
                   sprintf(buff2, pattern, dec1, dec2, dec3, dec4, dec5, dec6,
                           dec7, dec8, dec9, dec10, dec11));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e) {
  char buff1[2048];
  char buff2[2048];
  double fl = 666666.666;
  char *pattern = "%e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.0777557;
  char *pattern = "%-6e gkdbjgjhkd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -66.34555;
  char *pattern = "Here you can see plus flag realization: %+e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_flag_space) {
  char buff1[2048];
  char buff2[2048];
  double fl = 783.0;
  char *pattern = "Space flag % e - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  double fl = 78.77777777;
  char *pattern = " hash version %#e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.7777456;
  char *pattern = "Zero flag for int %0e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 1.111111;
  char *pattern = "%8e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_star_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 12345.6640;
  int width = 3;
  char *pattern = "%*e - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, fl),
                   sprintf(buff2, pattern, width, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 6666666.333333;
  char *pattern = "%.8e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 4.4;
  int accuracy = 3;
  char *pattern = "%.*e";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, fl),
                   sprintf(buff2, pattern, accuracy, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_long_length) {
  char buff1[2048];
  char buff2[2048];
  double fl = 345.333215;
  char *pattern = "%le";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_e_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long double fl = 385868.25254543;
  char *pattern = "%Le";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_e_many_flags) {
  char buff1[2048];
  char buff2[2048];
  double fl1 = -911.111111111;
  double fl2 = 111.0;
  double fl3 = 0;
  double fl4 = -32767.543645;
  double fl5 = 32767.11111;
  double fl6 = 0.22222;
  double fl7 = 0.54300;
  double fl8 = -900.0000;
  long double fl9 = 543.124143242342;
  char *pattern =
      "(%e)-(%-5e)-(%+e)-(% e)-(%#e)-(%7e)-(%2e)-(%.4e)-(%le)-(%Le)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl1, fl2, fl3, fl4, fl5, fl6,
                               fl7, fl8, fl5, fl9),
                   sprintf(buff2, pattern, fl1, fl2, fl3, fl4, fl5, fl6, fl7,
                           fl8, fl5, fl9));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E) {
  char buff1[2048];
  char buff2[2048];
  double fl = 666666.666;
  char *pattern = "%E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.0777557;
  char *pattern = "%-6E gkdbjgjhkd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -66.34555;
  char *pattern = "Here you can see plus flag realization: %+E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_flag_space) {
  char buff1[2048];
  char buff2[2048];
  double fl = 783.0;
  char *pattern = "Space flag % E - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  double fl = 78.77777777;
  char *pattern = " hash version %#E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.7777456;
  char *pattern = "Zero flag for int %0E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 1.111111;
  char *pattern = "%8E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_star_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 12345.6640;
  int width = 3;
  char *pattern = "%*E - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, fl),
                   sprintf(buff2, pattern, width, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 6666666.333333;
  char *pattern = "%.8E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 4.4;
  int accuracy = 3;
  char *pattern = "%.*E";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, fl),
                   sprintf(buff2, pattern, accuracy, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_long_length) {
  char buff1[2048];
  char buff2[2048];
  double fl = 345.333215;
  char *pattern = "%lE";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_E_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long double fl = 385868.25254543;
  char *pattern = "%LE";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_E_many_flags) {
  char buff1[2048];
  char buff2[2048];
  double fl1 = -911.111111111;
  double fl2 = 111.0;
  double fl3 = 0;
  double fl4 = -32767.543645;
  double fl5 = 32767.11111;
  double fl6 = 0.22222;
  double fl7 = 0.54300;
  double fl8 = -900.0000;
  long double fl9 = 543.124143242342;
  char *pattern =
      "(%E)-(%-5E)-(%+E)-(% E)-(%#E)-(%7E)-(%2E)-(%.4E)-(%lE)-(%LE)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl1, fl2, fl3, fl4, fl5, fl6,
                               fl7, fl8, fl5, fl9),
                   sprintf(buff2, pattern, fl1, fl2, fl3, fl4, fl5, fl6, fl7,
                           fl8, fl5, fl9));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g) {
  char buff1[2048];
  char buff2[2048];
  double fl = 666666.666;
  char *pattern = "%g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.0777557;
  char *pattern = "%-6g gkdbjgjhkd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -66.34555;
  char *pattern = "Here you can see plus flag realization: %+g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_flag_space) {
  char buff1[2048];
  char buff2[2048];
  double fl = 783.0;
  char *pattern = "Space flag % g - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  double fl = 78.77777777;
  char *pattern = " hash version %#g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.7777456;
  char *pattern = "Zero flag for int %0g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 1.111111;
  char *pattern = "%8g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_star_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 12345.6640;
  int width = 3;
  char *pattern = "%*g - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, fl),
                   sprintf(buff2, pattern, width, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 6666666.333333;
  char *pattern = "%.8g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 4.4;
  int accuracy = 3;
  char *pattern = "%.*g";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, fl),
                   sprintf(buff2, pattern, accuracy, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_long_length) {
  char buff1[2048];
  char buff2[2048];
  double fl = 345.333215;
  char *pattern = "%lg";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_g_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long double fl = 385868.25254543;
  char *pattern = "%Lg";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_g_many_flags) {
  char buff1[2048];
  char buff2[2048];
  double fl1 = -911.111111111;
  double fl2 = 111.0;
  double fl3 = 0;
  double fl4 = -32767.543645;
  double fl5 = 32767.11111;
  double fl6 = 0.22222;
  double fl7 = 0.54300;
  double fl8 = -900.0000;
  long double fl9 = 543.124143242342;

  char *pattern =
      "(%g)-(%-5g)-(%+g)-(% g)-(%#g)-(%7g)-(%2g)-(%.4g)-(%lg)-(%Lg)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl1, fl2, fl3, fl4, fl5, fl6,
                               fl7, fl8, fl5, fl9),
                   sprintf(buff2, pattern, fl1, fl2, fl3, fl4, fl5, fl6, fl7,
                           fl8, fl5, fl9));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G) {
  char buff1[2048];
  char buff2[2048];
  double fl = 666666.666;
  char *pattern = "%G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.0777557;
  char *pattern = "%-6G gkdbjgjhkd";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  double fl = -66.34555;
  char *pattern = "Here you can see plus flag realization: %+G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_flag_space) {
  char buff1[2048];
  char buff2[2048];
  double fl = 783.0;
  char *pattern = "Space flag % G - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  double fl = 78.77777777;
  char *pattern = " hash version %#G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  double fl = -0.7777456;
  char *pattern = "Zero flag for int %0G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 1.111111;
  char *pattern = "%8G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_star_width) {
  char buff1[2048];
  char buff2[2048];
  double fl = 12345.6640;
  int width = 1;
  char *pattern = "%*G - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, fl),
                   sprintf(buff2, pattern, width, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 6666666.333333;
  char *pattern = "%.8G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  double fl = 4.4;
  int accuracy = 3;
  char *pattern = "%.*G";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, fl),
                   sprintf(buff2, pattern, accuracy, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_long_length) {
  char buff1[2048];
  char buff2[2048];
  double fl = 345.333215;
  char *pattern = "%lG";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_G_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long double fl = 385868.25254543;
  char *pattern = "%LG";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl),
                   sprintf(buff2, pattern, fl));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_G_many_flags) {
  char buff1[2048];
  char buff2[2048];
  double fl1 = -911.111111111;
  double fl2 = 111.0;
  double fl3 = 0;
  double fl4 = -32767.543645;
  double fl5 = 32767.11111;
  double fl6 = 0.22222;
  double fl7 = 0.54300;
  double fl8 = -900.0000;
  long double fl9 = 543.124143242342;

  char *pattern =
      "(%G)-(%-5G)-(%+G)-(% G)-(%#G)-(%7G)-(%2G)-(%.4G)-(%lG)-(%LG)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, fl1, fl2, fl3, fl4, fl5, fl6,
                               fl7, fl8, fl5, fl9),
                   sprintf(buff2, pattern, fl1, fl2, fl3, fl4, fl5, fl6, fl7,
                           fl8, fl5, fl9));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x) {
  char buff1[2048];
  char buff2[2048];
  int dec = 666;
  char *pattern = "%x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "%-10x - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Here you can see plus flag realization: %+x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_flag_space) {
  char buff1[2048];
  char buff2[2048];
  int dec = 4567;
  char *pattern = "Space flag % x - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  int dec = 7890;
  char *pattern = " hash version %#x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Zero flag for int %0x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = 115;
  char *pattern = "%10x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_star_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = -6782;
  int width = 4;
  char *pattern = "%*x - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, dec),
                   sprintf(buff2, pattern, width, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = 33346;
  char *pattern = "%.8x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = -412;
  int accuracy = 7;
  char *pattern = "%.*x";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, dec),
                   sprintf(buff2, pattern, accuracy, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_short_length) {
  char buff1[2048];
  char buff2[2048];
  short int dec = 1;
  char *pattern = "%hx";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_long_length) {
  char buff1[2048];
  char buff2[2048];
  long int dec = -675433;
  char *pattern = "%lx";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_x_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long long int dec = 100000000;
  char *pattern = "%Lx";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_x_many_flags) {
  char buff1[2048];
  char buff2[2048];
  int dec1 = -911;
  int dec2 = 111;
  int dec3 = 0;
  int dec4 = -32767;
  int dec5 = 32767;
  int dec6 = 544;
  int dec7 = 55;
  int dec8 = -900;
  short int dec9 = 654;
  long int dec10 = 12345;
  long long int dec11 = 876543234;
  char *pattern =
      "(%x)-(%-10x)-(%+x)-(% x)-(%#x)-(%0x)-(%2x)-(%.4x)-(%hx)-(%lx)-(%Lx)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec1, dec2, dec3, dec4, dec5,
                               dec6, dec7, dec8, dec9, dec10, dec11),
                   sprintf(buff2, pattern, dec1, dec2, dec3, dec4, dec5, dec6,
                           dec7, dec8, dec9, dec10, dec11));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X) {
  char buff1[2048];
  char buff2[2048];
  int dec = 666;
  char *pattern = "%X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "%-10X - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Here you can see plus flag realization: %+X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_flag_space) {
  char buff1[2048];
  char buff2[2048];
  int dec = 4567;
  char *pattern = "Space flag % X - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  int dec = 7890;
  char *pattern = " hash version %#X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  int dec = -911;
  char *pattern = "Zero flag for int %0X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = 115;
  char *pattern = "%10X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_star_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = -6782;
  int width = 4;
  char *pattern = "%*X - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, dec),
                   sprintf(buff2, pattern, width, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = 33346;
  char *pattern = "%.8X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = -412;
  int accuracy = 7;
  char *pattern = "%.*X";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, dec),
                   sprintf(buff2, pattern, accuracy, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_short_length) {
  char buff1[2048];
  char buff2[2048];
  short int dec = -1000;
  char *pattern = "%hX";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_long_length) {
  char buff1[2048];
  char buff2[2048];
  long int dec = 567895;
  char *pattern = "%lX";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_X_long_long_length) {
  char buff1[2048];
  char buff2[2048];
  long long int dec = -100000000;
  char *pattern = "%LX";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec),
                   sprintf(buff2, pattern, dec));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_X_many_flags) {
  char buff1[2048];
  char buff2[2048];
  int dec1 = -911;
  int dec2 = 111;
  int dec3 = 0;
  int dec4 = -32767;
  int dec5 = 32767;
  int dec6 = 544;
  int dec7 = 55;
  int dec8 = -900;
  short int dec9 = 7665;
  long int dec10 = -234433;
  long long int dec11 = 876543234;
  char *pattern =
      "(%X)-(%-10X)-(%+X)-(% X)-(%#X)-(%0X)-(%2X)-(%.4X)-(%hX)-(%lX)-(%LX)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, dec1, dec2, dec3, dec4, dec5,
                               dec6, dec7, dec8, dec9, dec10, dec11),
                   sprintf(buff2, pattern, dec1, dec2, dec3, dec4, dec5, dec6,
                           dec7, dec8, dec9, dec10, dec11));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "Hello world";
  char *pattern = "String = %s.";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "Sparta";
  char *pattern = "This is ch = %-5s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "Bla bla\0";
  char *pattern = "This is nevazhno dlya ch = %+s.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_flag_space) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "ququ!/n";
  char *pattern = "% s proverka probela!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "AMOGUS!";
  char *pattern = "%#s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "cccc";
  char *pattern = "%06s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "222!@#$^&*";
  char *pattern = "%10s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_star_width) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "bubububu bababa";
  int width = 4;
  char *pattern = "%*s - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, ch),
                   sprintf(buff2, pattern, width, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "test_test test !@#)98761";
  char *pattern = "%.7s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch),
                   sprintf(buff2, pattern, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_string_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "tt";
  int accuracy = 1;
  char *pattern = "%.*s";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, ch),
                   sprintf(buff2, pattern, accuracy, ch));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_string_many_flags) {
  char buff1[2048];
  char buff2[2048];
  char *ch1 = "qq";
  char *ch2 = "132";
  char *ch3 = "a a b";
  char *ch4 = "\n\n";
  char *ch5 = "pupupu";
  char *ch6 = "123X1";
  char *ch7 = "2+-.";
  char *ch8 = "\0\0";
  char *pattern = "(%s)-(%-10s)-(%+s)-(% s)-(%#s)-(%0s)-(%2s)-(%.4s)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, ch1, ch2, ch3, ch4, ch5, ch6,
                               ch7, ch8, ch1, ch2),
                   sprintf(buff2, pattern, ch1, ch2, ch3, ch4, ch5, ch6, ch7,
                           ch8, ch1, ch2));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer) {
  char buff1[2048];
  char buff2[2048];
  int dec = 666;
  int *ptr = &dec;
  char *pattern = "%p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_flag_minus) {
  char buff1[2048];
  char buff2[2048];
  char ch = 'q';
  char *ptr = &ch;
  char *pattern = "%-p - now you know that.";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_flag_plus) {
  char buff1[2048];
  char buff2[2048];
  float fl = 6.42435;
  float *ptr = &fl;
  char *pattern = "Here you can see plus flag realization: %+p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_flag_space) {
  char buff1[2048];
  char buff2[2048];
  int dec = -4567;
  int *ptr = &dec;
  char *pattern = "Space flag % p - here you are!";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_flag_hash) {
  char buff1[2048];
  char buff2[2048];
  double fl = 0.4444443;
  double *ptr = &fl;
  char *pattern = " hash version %#p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_flag_zero) {
  char buff1[2048];
  char buff2[2048];
  int dec = 0;
  int *ptr = &dec;
  char *pattern = "Zero flag for int %0p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_fixed_width) {
  char buff1[2048];
  char buff2[2048];
  char *ch = "bobaba";
  char **ptr = &ch;
  char *pattern = "%10p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_star_width) {
  char buff1[2048];
  char buff2[2048];
  int dec = -6782;
  int *ptr = &dec;
  int width = 4;
  char *pattern = "%*p - abcdef";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, width, ptr),
                   sprintf(buff2, pattern, width, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_fixed_accuracy) {
  char buff1[2048];
  char buff2[2048];
  int dec = 33346;
  int *ptr = &dec;
  char *pattern = "%.8p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr),
                   sprintf(buff2, pattern, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(one_pointer_star_accuracy) {
  char buff1[2048];
  char buff2[2048];
  unsigned int dec = 115;
  unsigned int *ptr = &dec;
  int accuracy = 7;
  char *pattern = "%.*p";
  ck_assert_int_eq(s21_sprintf(buff1, pattern, accuracy, ptr),
                   sprintf(buff2, pattern, accuracy, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(many_pointer_many_flags) {
  char buff1[2048];
  char buff2[2048];
  int dec1 = -911;
  int dec2 = 111;
  int dec3 = 0;
  int dec4 = -32767;
  int dec5 = 32767;
  int dec6 = 544;
  int dec7 = 55;
  int dec8 = -900;
  int *ptr1 = &dec1;
  int *ptr2 = &dec2;
  int *ptr3 = &dec3;
  int *ptr4 = &dec4;
  int *ptr5 = &dec5;
  int *ptr6 = &dec6;
  int *ptr7 = &dec7;
  int *ptr8 = &dec8;
  char *pattern = "(%p)-(%-10p)-(%+p)-(% p)-(%#p)-(%0p)-(%2p)-(%.4p)";

  ck_assert_int_eq(s21_sprintf(buff1, pattern, ptr1, ptr2, ptr3, ptr4, ptr5,
                               ptr6, ptr7, ptr8, ptr1, ptr2),
                   sprintf(buff2, pattern, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6,
                           ptr7, ptr8, ptr1, ptr2));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(all_types_test) {
  char buff1[2048];
  char buff2[2048];

  int dec = -911;
  char ch = '1';
  char *str = "bebebe";
  unsigned int udec = 115;
  float fl = 5.4333333;
  double d = -65335.4333333;
  int *ptr = &dec;

  char *pattern = "%-d %c %s %u %.5f %o %f %p";
  ck_assert_int_eq(
      s21_sprintf(buff1, pattern, dec, ch, str, udec, fl, d, fl, ptr),
      sprintf(buff2, pattern, dec, ch, str, udec, fl, d, fl, ptr));
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

Suite *suite_s21_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("tc_sprintf");

  tcase_add_test(tc, one_char);
  tcase_add_test(tc, one_char_flag_minus);
  tcase_add_test(tc, one_char_flag_plus);
  tcase_add_test(tc, one_char_flag_space);
  tcase_add_test(tc, one_char_flag_hash);
  tcase_add_test(tc, one_char_flag_zero);
  tcase_add_test(tc, one_char_fixed_width);
  tcase_add_test(tc, one_char_star_width);
  tcase_add_test(tc, one_char_fixed_accuracy);
  tcase_add_test(tc, one_char_star_accuracy);
  tcase_add_test(tc, many_char_many_flags);
  tcase_add_test(tc, one_int);
  tcase_add_test(tc, one_int_flag_minus);
  tcase_add_test(tc, one_int_flag_plus);
  tcase_add_test(tc, one_int_flag_space);
  tcase_add_test(tc, one_int_flag_hash);
  tcase_add_test(tc, one_int_flag_zero);
  tcase_add_test(tc, one_int_fixed_width);
  tcase_add_test(tc, one_int_star_width);
  tcase_add_test(tc, one_int_fixed_accuracy);
  tcase_add_test(tc, one_int_star_accuracy);
  tcase_add_test(tc, one_int_short_length);
  tcase_add_test(tc, one_int_long_length);
  tcase_add_test(tc, one_int_long_long_length);
  tcase_add_test(tc, many_int_many_flags);
  tcase_add_test(tc, one_float);
  tcase_add_test(tc, one_float_flag_minus);
  tcase_add_test(tc, one_float_flag_plus);
  tcase_add_test(tc, one_float_flag_space);
  tcase_add_test(tc, one_float_flag_hash);
  tcase_add_test(tc, one_float_flag_zero);
  tcase_add_test(tc, one_float_fixed_width);
  tcase_add_test(tc, one_float_star_width);
  tcase_add_test(tc, one_float_fixed_accuracy);
  tcase_add_test(tc, one_float_star_accuracy);
  tcase_add_test(tc, one_float_long_length);
  tcase_add_test(tc, one_float_long_long_length);
  tcase_add_test(tc, many_float_many_flags);
  tcase_add_test(tc, one_Uint);
  tcase_add_test(tc, one_Uint_flag_minus);
  tcase_add_test(tc, one_Uint_flag_plus);
  tcase_add_test(tc, one_Uint_flag_space);
  tcase_add_test(tc, one_Uint_flag_hash);
  tcase_add_test(tc, one_Uint_flag_zero);
  tcase_add_test(tc, one_Uint_fixed_width);
  tcase_add_test(tc, one_Uint_star_width);
  tcase_add_test(tc, one_Uint_fixed_accuracy);
  tcase_add_test(tc, one_Uint_star_accuracy);
  tcase_add_test(tc, one_Uint_short_length);
  tcase_add_test(tc, one_Uint_long_length);
  tcase_add_test(tc, one_Uint_long_long_length);
  tcase_add_test(tc, many_Uint_many_flags);
  tcase_add_test(tc, one_octal);
  tcase_add_test(tc, one_octal_flag_minus);
  tcase_add_test(tc, one_octal_flag_plus);
  tcase_add_test(tc, one_octal_flag_space);
  tcase_add_test(tc, one_octal_flag_hash);
  tcase_add_test(tc, one_octal_flag_zero);
  tcase_add_test(tc, one_octal_fixed_width);
  tcase_add_test(tc, one_octal_star_width);
  tcase_add_test(tc, one_octal_fixed_accuracy);
  tcase_add_test(tc, one_octal_star_accuracy);
  tcase_add_test(tc, one_octal_short_length);
  tcase_add_test(tc, one_octal_long_length);
  tcase_add_test(tc, one_octal_long_long_length);
  tcase_add_test(tc, many_octal_many_flags);
  tcase_add_test(tc, one_e);
  tcase_add_test(tc, one_e_flag_minus);
  tcase_add_test(tc, one_e_flag_plus);
  tcase_add_test(tc, one_e_flag_space);
  tcase_add_test(tc, one_e_flag_hash);
  tcase_add_test(tc, one_e_flag_zero);
  tcase_add_test(tc, one_e_fixed_width);
  tcase_add_test(tc, one_e_star_width);
  tcase_add_test(tc, one_e_fixed_accuracy);
  tcase_add_test(tc, one_e_star_accuracy);
  tcase_add_test(tc, one_e_long_length);
  tcase_add_test(tc, one_e_long_long_length);
  tcase_add_test(tc, many_e_many_flags);
  tcase_add_test(tc, one_E);
  tcase_add_test(tc, one_E_flag_minus);
  tcase_add_test(tc, one_E_flag_plus);
  tcase_add_test(tc, one_E_flag_space);
  tcase_add_test(tc, one_E_flag_hash);
  tcase_add_test(tc, one_E_flag_zero);
  tcase_add_test(tc, one_E_fixed_width);
  tcase_add_test(tc, one_E_star_width);
  tcase_add_test(tc, one_E_fixed_accuracy);
  tcase_add_test(tc, one_E_star_accuracy);
  tcase_add_test(tc, one_E_long_length);
  tcase_add_test(tc, one_E_long_long_length);
  tcase_add_test(tc, many_E_many_flags);
  tcase_add_test(tc, one_g);
  tcase_add_test(tc, one_g_flag_minus);
  tcase_add_test(tc, one_g_flag_plus);
  tcase_add_test(tc, one_g_flag_space);
  tcase_add_test(tc, one_g_flag_hash);
  tcase_add_test(tc, one_g_flag_zero);
  tcase_add_test(tc, one_g_fixed_width);
  tcase_add_test(tc, one_g_star_width);
  tcase_add_test(tc, one_g_fixed_accuracy);
  tcase_add_test(tc, one_g_star_accuracy);
  tcase_add_test(tc, one_g_long_length);
  tcase_add_test(tc, one_g_long_long_length);
  tcase_add_test(tc, many_g_many_flags);
  tcase_add_test(tc, one_G);
  tcase_add_test(tc, one_G_flag_minus);
  tcase_add_test(tc, one_G_flag_plus);
  tcase_add_test(tc, one_G_flag_space);
  tcase_add_test(tc, one_G_flag_hash);
  tcase_add_test(tc, one_G_flag_zero);
  tcase_add_test(tc, one_G_fixed_width);
  tcase_add_test(tc, one_G_star_width);
  tcase_add_test(tc, one_G_fixed_accuracy);
  tcase_add_test(tc, one_G_star_accuracy);
  tcase_add_test(tc, one_G_long_length);
  tcase_add_test(tc, one_G_long_long_length);
  tcase_add_test(tc, many_G_many_flags);
  tcase_add_test(tc, one_x);
  tcase_add_test(tc, one_x_flag_minus);
  tcase_add_test(tc, one_x_flag_plus);
  tcase_add_test(tc, one_x_flag_space);
  tcase_add_test(tc, one_x_flag_hash);
  tcase_add_test(tc, one_x_flag_zero);
  tcase_add_test(tc, one_x_fixed_width);
  tcase_add_test(tc, one_x_star_width);
  tcase_add_test(tc, one_x_fixed_accuracy);
  tcase_add_test(tc, one_x_star_accuracy);
  tcase_add_test(tc, one_x_short_length);
  tcase_add_test(tc, one_x_long_length);
  tcase_add_test(tc, one_x_long_long_length);
  tcase_add_test(tc, many_x_many_flags);
  tcase_add_test(tc, one_X);
  tcase_add_test(tc, one_X_flag_minus);
  tcase_add_test(tc, one_X_flag_plus);
  tcase_add_test(tc, one_X_flag_space);
  tcase_add_test(tc, one_X_flag_hash);
  tcase_add_test(tc, one_X_flag_zero);
  tcase_add_test(tc, one_X_fixed_width);
  tcase_add_test(tc, one_X_star_width);
  tcase_add_test(tc, one_X_fixed_accuracy);
  tcase_add_test(tc, one_X_star_accuracy);
  tcase_add_test(tc, one_X_short_length);
  tcase_add_test(tc, one_X_long_length);
  tcase_add_test(tc, one_X_long_long_length);
  tcase_add_test(tc, many_X_many_flags);
  tcase_add_test(tc, one_string);
  tcase_add_test(tc, one_string_flag_minus);
  tcase_add_test(tc, one_string_flag_plus);
  tcase_add_test(tc, one_string_flag_space);
  tcase_add_test(tc, one_string_flag_hash);
  tcase_add_test(tc, one_string_flag_zero);
  tcase_add_test(tc, one_string_fixed_width);
  tcase_add_test(tc, one_string_star_width);
  tcase_add_test(tc, one_string_fixed_accuracy);
  tcase_add_test(tc, one_string_star_accuracy);
  tcase_add_test(tc, many_string_many_flags);
  tcase_add_test(tc, one_pointer);
  tcase_add_test(tc, one_pointer_flag_minus);
  tcase_add_test(tc, one_pointer_flag_plus);
  tcase_add_test(tc, one_pointer_flag_space);
  tcase_add_test(tc, one_pointer_flag_hash);
  tcase_add_test(tc, one_pointer_flag_zero);
  tcase_add_test(tc, one_pointer_fixed_width);
  tcase_add_test(tc, one_pointer_star_width);
  tcase_add_test(tc, one_pointer_fixed_accuracy);
  tcase_add_test(tc, one_pointer_star_accuracy);
  tcase_add_test(tc, many_pointer_many_flags);
  tcase_add_test(tc, all_types_test);

  suite_add_tcase(s, tc);
  return s;
}