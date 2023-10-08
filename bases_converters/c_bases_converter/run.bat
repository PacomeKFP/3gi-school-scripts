rm old_app.exe
REN app.exe old_app.exe
gcc src\main.c src\menu_handlers.c lib\*.c -o app -I include
app