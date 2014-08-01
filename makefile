G:=gcc
I:=-Iinclude
all:=bin/main
DEP:=obj/menu.o
DEP+=obj/node.o
DEP+=obj/file.o
DEP+=obj/register.o
DEP+=obj/login.o
DEP+=obj/main.o
DEP+=obj/user.o
DEP+=obj/admin.o
DEP+=obj/third.o
DEP+=obj/secret.o
${all}:${DEP}
	${G} obj/menu.o obj/node.o obj/file.o obj/register.o obj/login.o obj/user.o obj/main.o obj/admin.o obj/third.o obj/secret.o -o bin/main
obj/%.o:src/%.c
	${G} -c $^ ${I} -o $@ -g -Wall

.PHONY:clean

clean:
	rm -rf ${all} ${DEP}

