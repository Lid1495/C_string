#include "../s21_string.h"

int parseFlag(char symb, Flags* flags) {
  /*
  эта функция крч парсит флаг. В блоках иф смотрит какой и включает его.
  Если флаг мы смогли включить - возвращаем 1
  если не смогли, значит это не флаг а что-то другое, возвращаем 0
  */
  int result = 1;
  if (symb == '-') {
    flags->flag_minus = 1;
  } else if (symb == '+') {
    flags->flag_plus = 1;
  } else if (symb == ' ') {
    flags->flag_space = 1;
  } else if (symb == '#') {
    flags->flag_hash = 1;
  } else if (symb == '0') {
    flags->flag_zero = 1;
  } else {
    result = 0;
  }
  return result;
}

int parseWidth(char symb, Flags* flags) {
  /*
  эта функция парсит ширину.
  если ввели * то включает флаг для ширины и возвращаем 1 (саму ширину потом
  возьмем из аргументов). если у нас число (47 < символ < 58 по аське) то
  умножением на 10 сдвигаем наши прошлые разряды и добавляем новый, возвращаем 2
  в ином случае пользователь ввел что-то другое, значит это не ширина и мы
  возвращаем 0
  */
  int result = 0;
  if (symb == '*') {
    flags->flag_width = 1;
    result = 1;
  } else if (symb > 47 && symb < 58) {
    flags->width *= 10;
    flags->width += symb - 48;
    result = 2;
  }
  return result;
}

int parseAccuracy(char symb, Flags* flags) {
  /*
  эта функция крч работает точно также как и функция для ширины.
  Поэтому она бесполезна тк делает одно и тоже и можно использовать просто одну
  функцию, но уберу ее потом, щас лень
  */
  int result = 0;
  if (symb == '*') {
    flags->flag_accuracy = 1;
    flags->accuracy_setted = 1;
    result = 1;
  } else if (symb > 47 && symb < 58) {
    flags->accuracy_setted = 1;
    flags->accuracy *= 10;
    flags->accuracy += symb - 48;
    result = 2;
  }
  return result;
}

int is_specifier(char symb) {
  /*
  вот эта проверяет является ли символ спецификатором.
  если да возрващает 1
  если нет то 0
  */
  int result = 0;
  if (symb == 'c' || symb == 'd' || symb == 'i' || symb == 'e' || symb == 'E' ||
      symb == 'f' || symb == 'g' || symb == 'G' || symb == 'o' || symb == 's' ||
      symb == 'u' || symb == 'x' || symb == 'X' || symb == 'p' || symb == 'n') {
    result = 1;
  }
  return result;
}

Flags parseSpecifier(s21_size_t* format_ind, const char* str) {
  /*
  sprintf: %[флаги][ширина][.точность][длина]спецификатор
  sscanf: %[*][ширина][длина]спецификатор.
  */
  int step = 0;
  /*
  тут я решил разбить парсинг на шаги. для этого нужна переменная выше
  у нас будет их 4:
      1. парсинг флагов
      2. парсинг ширины
      3. парсинг точности
      4. парсинг длинны и самого спецификатора
  */
  int parse_accuracy = 0;  // флаг надо ли парсить точность
  Flags flags = {0};
  for (; step < 4 && str[*format_ind] != '\0'; (*format_ind)++) {
    // parse flags
    if (step == 0) {
      /*
      если у нас шаг первый, пытаемся спарсить флаг.
      если функция вернула 1 (спарсила его) то берем следующий символ в строке
      в ином случае переходим к следующему шагу парсингу ширины
      */
      if (parseFlag(str[*format_ind], &flags) != 0) {
        continue;
      } else {
        step++;
      }
    }
    // parse width
    if (step == 1) {
      /*
      тут парсим ширину.
      если функция спарсила * и вернула 1, то переходим к следующему шагу
      парсинга точности и берем следующий символ если функция спарсила число и
      вернула 2, то берем следующий символ и пытаемся спарсить его если функция
      вернула 0, значит мы уже спарсили ширину или ее не ввели и переходим в
      следующему шагу
      */
      int width_status = parseWidth(str[*format_ind], &flags);
      if (width_status == 1) {
        step++;
        continue;
      } else if (width_status == 2) {
        continue;
      } else {
        step++;
      }
    }
    // parse accuracy
    if (str[*format_ind] == '.') {
      /*
      тут мы крч проверяем что мы встретили точку, значит нам ввели точность и
      мы включаем флаг и берем следующий символ
      */
      parse_accuracy = 1;
      continue;
    }
    if (step == 2) {
      // maybe add error if after . not number...
      /*
      тут все тоже самое что и с шириной, но еще проверяем стоит ли флаг для
      парсинга точности когда ее спарсим, то флаг 2, что значит что она была
      спаршена
      */
      int accuracy_status;
      if (parse_accuracy == 1 &&
          (accuracy_status = parseAccuracy(str[*format_ind], &flags)) != 0) {
        if (accuracy_status == 1) {
          step++;
          flags.accuracy_setted = 1;
          continue;
        } else if (accuracy_status == 2) {
          flags.accuracy_setted = 1;
          continue;
        }
      } else {
        parse_accuracy = 2;
        step++;
      }
    }
    // parse len and specifier type
    if (step == 3) {
      /*
      если наш символ это h или l или L то записываем его в спец символ длинны и
      берем следующий если наш символ это то мы его записываем в type затем наш
      шаг увеличиваем чтобы окончательно выйти из цикла
      */
      char symb = str[*format_ind];
      if (symb == 'h' || symb == 'l' || symb == 'L') {
        flags.flag_specialSymbol = symb;
        continue;
      } else if (is_specifier(symb) == 1) {
        flags.type = symb;
      }
      step++;
    }
  }
  // тут когда-нибудь будет проверка что спецификатор спаршен...
  // или ваша реклама!
  //(*format_ind)++;
  return flags;
}

void reverse(char* arr, int ind) {
  for (int len = s21_strlen(arr) - 1; len > ind; len--, ind++) {
    char ch = arr[ind];
    arr[ind] = arr[len];
    arr[len] = ch;
  }
}

void itoa(int x, char* buff, Flags flags) {
  int ind = s21_strlen(buff);
  // ставим первым символом знак или пробел, если включен флаг
  if (x < 0) {
    buff[ind] = '-';
    x *= -1;
    ind++;
  } else if (flags.flag_plus && s21_strstr("gGfeE", &flags.type) == s21_NULL) {
    buff[ind] = '+';
    ind++;
  } else if (flags.flag_plus == 0 && flags.flag_space &&
             s21_strstr("gGfeE", &flags.type) == s21_NULL) {
    buff[ind] = ' ';
    ind++;
  }
  if (x == 0) {
    buff[ind] = '0';
  }
  for (int temp_ind = ind; x > 0; temp_ind++) {
    buff[temp_ind] = (x % 10) + 48;
    x /= 10;
  }
  reverse(buff, ind);
}

void otoa(unsigned long long x, char* buff, Flags flags, int r) {
  int ind = 0;
  if (flags.flag_hash && flags.type == 'o') {
    buff[ind] = '0';
    ind++;
  }
  if (x == 0) {
    buff[ind] = '0';
  }
  for (int temp_ind = ind; x > 0; temp_ind++) {
    buff[temp_ind] = (x % r) + 48;
    x /= r;
  }
  reverse(buff, ind);
}

void xtoa(unsigned long long x, char* buff, Flags flags, int upper) {
  int ind = 0;
  char symb = 'a';
  if (upper) {
    symb = 'A';
  }
  if (flags.flag_hash) {
    buff[ind++] = '0';
    buff[ind++] = upper ? 'X' : 'x';
  }
  if (x == 0) {
    buff[ind] = '0';
  }
  for (int temp_ind = ind; x > 0; temp_ind++) {
    int temp = x % 16;
    if (temp < 10) {
      buff[temp_ind] = temp + 48;
    } else {
      buff[temp_ind] = temp + symb - 10;
    }
    x /= 16;
  }
  reverse(buff, ind);
}

void reduce(char* buff, int ind) {
  if (buff[ind] == '.') {
    reduce(buff, ind - 1);
  }
  if (buff[ind] > 57 || buff[ind] < 48) {
    return;
  }
  if (buff[ind] == '9') {
    buff[ind] = '0';
    reduce(buff, ind - 1);
  } else {
    buff[ind] += 1;
  }
}

void ftoa(long double x, char* buff, Flags flags) {
  if (flags.accuracy_setted == 0) {
    flags.accuracy = 6;
  }
  if (x < 0) {
    buff[0] = '-';
    x *= -1;
  } else if (flags.flag_plus) {
    buff[0] = '+';
  } else if (flags.flag_space) {
    buff[0] = ' ';
  }
  itoa(x, buff, flags);
  int ind = s21_strlen(buff);
  if (flags.accuracy > 0) {
    buff[ind] = '.';
    ind++;
  }
  double decimal = x - (long)x;
  for (int accuracy = flags.accuracy; accuracy > 0; accuracy--, ind++) {
    decimal *= 10;
    buff[ind] = ((int)decimal % 10) + 48;
    decimal = decimal - (int)decimal;
  }
  decimal *= 10;
  int min = flags.type == 'g' || flags.type == 'G' ? -1 : 0;
  if (((int)decimal % 10) >= 5 && ((int)(decimal * 10) % 10) > min) {
    reduce(buff, ind - 1);
  }
}

void etoa(double x, char* buff, Flags flags, int reg) {
  char ch = 'e';
  if (reg) ch = 'E';
  char sign = '+';
  if (flags.accuracy_setted == 0) {
    flags.accuracy = 6;
    flags.accuracy_setted = 1;
  }
  long long num = (long long)x;
  if (num < 0) {
    num *= -1;
  }
  int num_count = 1;
  long long temp_num = num;
  if (num > 0) {
    for (; temp_num > 9; temp_num /= 10, num_count++)
      ;
    for (int temp = num_count; temp > 1; temp--, x /= 10)
      ;
  } else if (x != 0.0) {
    sign = '-';
    for (; (long long)x == 0; num_count++, x *= 10)
      ;
  }
  ftoa(x, buff, flags);
  int ind = s21_strlen(buff);
  buff[ind++] = ch;
  buff[ind++] = sign;
  if (num_count - 1 > 9) {
    buff[ind++] = (num_count - 1) / 10 + '0';
    buff[ind++] = (num_count - 1) % 10 + '0';
  } else {
    buff[ind++] = '0';
    buff[ind++] = (num_count - 1) + '0';
  }
}

void gtoa(double x, char* buff, Flags flags, int reg) {
  if (flags.accuracy_setted == 0) {
    flags.accuracy = 6;
    flags.accuracy_setted = 1;
  }
  long long num = (long long)x;
  if (num < 0) {
    num *= -1;
  }
  if (num == 0) {
    flags.accuracy += 1;  // costyl
    if (flags.flag_minus) {
      flags.accuracy +=
          1;  // eshe odin costyl. hz kak on vse chinit, no ono rabotaet
    }
  }
  int num_count = 1;
  for (long long temp_num = num; temp_num > 9; temp_num /= 10, num_count++)
    ;
  if (num_count <= flags.accuracy) {
    flags.accuracy -= num_count;
    ftoa(x, buff, flags);
    int ind = s21_strlen(buff) - 1;
    int count_space = 0;
    for (; buff[ind] == '0' && ind >= 0; count_space++, ind--)
      ;
    if (buff[ind] == '.') {
      buff[ind] = '\0';
    } else {
      buff[++ind] = '\0';
    }
  } else {
    flags.accuracy -= 1;
    etoa(x, buff, flags, reg);
  }
}

void ptoa(unsigned long long x, char* buff) {
  int ind = 0;
  char symb = 'a';
  // ставим первым символом знак или пробел, если включен флаг
  buff[ind++] = '0';
  buff[ind++] = 'x';
  if (x == 0) {
    buff[ind] = '0';
  }
  // переворачиваем число чтобы записать в массив
  for (int temp_ind = ind; x > 0; temp_ind++) {
    int temp = x % 16;
    if (temp < 10) {
      buff[temp_ind] = temp + 48;
    } else {
      buff[temp_ind] = temp + symb - 10;
    }
    x /= 16;
  }
  reverse(buff, ind);
}

void replace_number(Flags flags, int* symbolsCount, char* str, char* num) {
  char fill_symbol = ' ';
  if (flags.flag_zero) {
    fill_symbol = '0';
  }
  int has_flag = (num[0] == ' ' || num[0] == '-' || num[0] == '+');
  if (flags.accuracy > 0 &&
      (int)(flags.accuracy - (s21_strlen(num) - has_flag)) > 0 &&
      s21_strstr("eEgGfncsp", &flags.type) == s21_NULL) {
    int min = 0;
    if (has_flag) min++;
    int zero_count = flags.accuracy - s21_strlen(num) + min;
    for (int i = s21_strlen(num) + zero_count - 1; i >= min; i--) {
      if (i > zero_count - 1 + min) {
        num[i] = num[i - zero_count];
      } else {
        num[i] = '0';
      }
    }
  }

  if (s21_strlen(num) < flags.width && flags.flag_minus == 0) {
    for (; flags.width > s21_strlen(num); flags.width--, (*symbolsCount)++) {
      str[*symbolsCount] = fill_symbol;
    }
  }
  for (s21_size_t i = 0; i < s21_strlen(num); i++, (*symbolsCount)++) {
    str[*symbolsCount] = num[i];
  }
  if (flags.type == 'c' && num[0] == '\0') {
    str[*symbolsCount] = '\0';
    (*symbolsCount)++;
  }
  if (s21_strlen(num) < flags.width && flags.flag_minus) {
    for (; flags.width > s21_strlen(num); flags.width--, (*symbolsCount)++) {
      str[*symbolsCount] = fill_symbol;
    }
  }
}

void stoa(char* x, char* buff, Flags flags) {
  for (s21_size_t i = 0; i < s21_strlen(x); i++) {
    if (flags.accuracy_setted && i == (s21_size_t)flags.accuracy) {
      break;
    }
    buff[i] = x[i];
  }
}

void parse_arg_number(Flags flags, char* buff, va_list* args) {
  if (flags.type == 'd') {
    itoa(va_arg(*args, int), buff, flags);

  } else if (flags.type == 'i') {
    itoa(va_arg(*args, int), buff, flags);

  } else if (flags.type == 'o') {
    if (flags.flag_specialSymbol == 'L') {
      otoa(va_arg(*args, unsigned int), buff, flags, 8);
    } else if (flags.flag_specialSymbol == 'l') {
      otoa(va_arg(*args, long int), buff, flags, 8);
    } else {
      otoa(va_arg(*args, unsigned int), buff, flags, 8);
    }

  } else if (flags.type == 'x') {
    if (flags.flag_specialSymbol == 'h') {
      xtoa((unsigned short)va_arg(*args, unsigned int), buff, flags, 0);
    } else if (flags.flag_specialSymbol == 'L') {
      xtoa(va_arg(*args, unsigned int), buff, flags, 0);
    } else {
      xtoa(va_arg(*args, unsigned long), buff, flags, 0);
    }

  } else if (flags.type == 'X') {
    if (flags.flag_specialSymbol == 'h') {
      xtoa((unsigned short)va_arg(*args, unsigned), buff, flags, 1);
    } else if (flags.flag_specialSymbol == 'L') {
      xtoa(va_arg(*args, unsigned int), buff, flags, 1);
    } else {
      xtoa(va_arg(*args, unsigned long), buff, flags, 1);
    }

  } else if (flags.type == 'u') {
    if (flags.flag_specialSymbol == 'L') {
      otoa(va_arg(*args, unsigned int), buff, flags, 10);
    } else if (flags.flag_specialSymbol == 'l') {
      otoa(va_arg(*args, long int), buff, flags, 10);
    } else {
      otoa(va_arg(*args, long), buff, flags, 10);
    }

  } else if (flags.type == 'c') {
    buff[0] = va_arg(*args, int);

  } else if (flags.type == 's') {
    stoa(va_arg(*args, char*), buff, flags);

  } else if (flags.type == 'p') {
    ptoa((unsigned long long)va_arg(*args, void*), buff);

  } else if (flags.type == 'f') {
    if (flags.flag_specialSymbol == 'L') {
      ftoa(va_arg(*args, long double), buff, flags);
    } else {
      ftoa(va_arg(*args, double), buff, flags);
    }

  } else if (flags.type == 'g') {
    if (flags.flag_specialSymbol == 'L') {
      gtoa(va_arg(*args, long double), buff, flags, 0);
    } else {
      gtoa(va_arg(*args, double), buff, flags, 0);
    }

  } else if (flags.type == 'G') {
    if (flags.flag_specialSymbol == 'L') {
      gtoa(va_arg(*args, long double), buff, flags, 1);
    } else {
      gtoa(va_arg(*args, double), buff, flags, 1);
    }

  } else if (flags.type == 'e') {
    if (flags.flag_specialSymbol == 'L') {
      etoa(va_arg(*args, long double), buff, flags, 0);
    } else {
      etoa(va_arg(*args, double), buff, flags, 0);
    }

  } else if (flags.type == 'E') {
    if (flags.flag_specialSymbol == 'L') {
      etoa(va_arg(*args, long double), buff, flags, 1);
    } else {
      etoa(va_arg(*args, double), buff, flags, 1);
    }
  }
}

void replaceSpicificator(Flags flags, int* symbolsCount, char* str,
                         va_list* args) {
  if (flags.flag_width) {
    flags.width = va_arg(*args, int);
  }
  if (flags.flag_accuracy) {
    flags.accuracy = va_arg(*args, int);
  }
  char type = flags.type;
  if (type != 'n') {
    char buff[1000] = {"\0"};
    parse_arg_number(flags, (char*)buff, args);
    replace_number(flags, symbolsCount, str, (char*)buff);
  } else if (type == 'n') {
    *(va_arg(*args, int*)) = *symbolsCount;
  }
}

int s21_sprintf(char* str, const char* format, ...) {
  s21_strncpy(str, "", 0);
  int symbolsCount = 0;
  va_list args;
  va_start(args, format);
  for (s21_size_t i = 0; i < s21_strlen(format); i++, symbolsCount++) {
    if (format[i] == '%') {
      i++;
      Flags flags = parseSpecifier(&i, format);
      replaceSpicificator(flags, &symbolsCount, str, &args);
      symbolsCount--;
      i--;
    } else {
      str[symbolsCount] = format[i];
    }
  }
  str[symbolsCount] = '\0';
  va_end(args);
  return symbolsCount;
}