for d in lib/*.c; do
    path=$(echo $d | tr "/." "\n")
    file_name=$(echo $path | cut -d " " -f 2)
    gcc -m32 -c $d -o obj/$file_name.o -I include -ffreestanding
done
