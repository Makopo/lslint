# run this on mingw before running creator_win*.bat

curl -O https://raw.githubusercontent.com/Sei-Lisa/kwdb/master/outputs/builtins.txt

echo "#ifdef _MSC_VER" > builtins_txt.cc
echo "#pragma execution_character_set(\"utf-8\")" >> builtins_txt.cc
echo "#endif" >> builtins_txt.cc
echo "const char *builtins_txt[] = {" >> builtins_txt.cc
sed -e '/^\/\//d; s/"/\\\"/g; s/^/"/; s/$/",/' builtins.txt >> builtins_txt.cc || { rm -f builtins_txt.cc ; false ; }
echo "(char*)0 };" >> builtins_txt.cc
