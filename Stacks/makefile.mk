a.out: st.o client.o
	gcc st.o client.o

st.o: dynamic_and_static_stacks.c stack_ops.h
	gcc -c dynamic_and_static_stacks.c

client.o: client.c stack_ops.h
	gcc -c client.c