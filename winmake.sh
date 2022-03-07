# Create bin directory
rm -rf bin
mkdir bin

############### CINO ###############

# cino_util
gcc -Wall -std=c99 -Iinclude/ -c src/cino_utils.c -o bin/cino_utils.obj

# cino
gcc -Wall -std=c99 -Iinclude/ -c src/cino.c -o bin/cino.obj
gcc -Wall -std=c99 bin/cino_utils.obj bin/cino.obj -o bin/cino.exe

############### TEST ###############

# test_cino_utils
gcc -Wall -std=c99 -Iinclude/ -c test/test_cino_utils.c -o bin/test_cino_utils.obj

# test_cino
gcc -Wall -std=c99 -Iinclude/ -c test/test_cino.c -o bin/test_cino.obj
gcc -Wall -std=c99 bin/cino_utils.obj bin/test_cino_utils.obj bin/test_cino.obj -o bin/test.cino.exe