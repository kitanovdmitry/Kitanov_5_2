/*
Автор: Китанов Дмитрий
Группа: СБС-001-О-01, подгруппа 2
Задача №5, вариант 2
Цель: Закодировать вводимую строку с помощью текста и дополнительного массива чисел
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int find_character (char *encoding_str, char *base_str,
                    int number_character,
                    int length_encoding_str, int length_base_str)
{
    for (int i = 0; i < length_base_str; i++)
    {
        if (encoding_str[number_character] == base_str[i])
        {
            return i;
        }
    }

    return -1;
}

void filling_additional_array(int *additional_array, int add_arr_size)
{
    for (int i = 0; i < add_arr_size; i++)
    {
        additional_array[i] = 200 + i;
    }
}

void encoder (char *encoding_str, int length_encoding_str, int *encoded_str)
{
    char base_str [] = {"When Israel was in Egypt land... Joe, shake a-like a Gioviano / So the God said: go down, Moses way down in Egypt land..."};
    const int add_arr_size = 150;
    int additional_array[add_arr_size];

    filling_additional_array(additional_array, add_arr_size);

    const int length_base_str = strlen(base_str);
    int char_pos = 0;
    bool char_is_found;

    for (int number_character = 0; number_character < length_encoding_str; number_character++)
    {
        char_pos = find_character(encoding_str, base_str,
                                  number_character,
                                  length_encoding_str, length_base_str);

        char_is_found = (char_pos >= 0);

        if (char_is_found)
        {
            encoded_str[number_character] = char_pos;
        }
        else
        {
            encoded_str[number_character] = additional_array[number_character];
        }
    }
}

int main()
{
    const int max_length = 150;
    char encoding_str[max_length];
    int *encoded_str;

    cout << "Enter your text(in English) for encoding(< 150 characters)\n";
    gets(encoding_str);
    cout << "Your text: " << encoding_str << "\n";

    const int length_encoding_str = strlen(encoding_str);
    encoded_str = new int[length_encoding_str];

    encoder(encoding_str, length_encoding_str, encoded_str);

    bool start_of_output = 0;

    for (int i = 0; i < length_encoding_str; i++)
    {
        if (i == start_of_output)
        {
            cout << "Your encoded text: ";
        }

        cout << encoded_str[i] << " ";
    }

    delete [] encoded_str;
    return 0;
}
