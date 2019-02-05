# LZW-compressor-C


Working in progress : 

- compress OK

- decompress working in progress

- Bit writing soon...

./lzw -[cd] -[fl] path or line 

c : compress

d : decompress

f : file

l : line

ex : ./lzw -c -f $path or ./lzw -c -l $line

With -f option, the program create a new file with .my_lzw at the end.

ex : ./lzw -c -f Makefile will create Makefile.my_lzw.

