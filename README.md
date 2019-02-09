# LZW-compressor-C


Working in progress : 

- compress OK

- decompress work for most of the case

- Bit writing soon...

./lzw -[cd] -[fl] path or line 

- c : compress

- d : decompress

- f : file

- l : line

ex : ./lzw -c -f $path or ./lzw -c -l $line

With -f option, the program create a new file with .my_lzw if you want to compress, or .txt if you decompress.

ex : ./lzw -c -f Makefile will create Makefile.my_lzw

ex : ./lzw -d -f Makefile.my_lzw will create Makefile.txt


Warning for decompression a file, the programm wait ".my_lzw" at the end of the path name ! 


To understand the lzw : https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/


