#include <stdio.h>
#include "coop.h"

/**
 * @brief Letter Frequency Demo
 */
int main() {
    char text[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
    str_tolower(text);

    hash_map_t *map = hash_map_new(Character_compare, Character_hash);

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            Character *c = Character_new(text[i]);
            if (hash_map_contains(map, c)) {
                Integer *count = hash_map_get(map, c);
                Integer_set(count, Integer_get(count) + 1);
                Character_delete(c);
            } else {
                pair_t *word = pair_new(c, Integer_new(1), Character_delete, Integer_delete);
                hash_map_put(map, word);
            }
        }
    }

    iterator_t *iter = hash_map_iterator_new(map);
    while (hash_map_iterator_has_next(iter)) {
        pair_t *pair = hash_map_iterator_next(iter);
        Character *c = pair_get_key(pair);
        Integer *count = pair_get_value(pair);
        printf("%c: %d\n", Character_get(c), Integer_get(count));
    }
    hash_map_iterator_delete(iter);

    hash_map_delete(map);

    return 0;
}
