# Systems::Get Dem Bugs

Do Now: What’s wrong with this function?

  


struct node * insert_front(struct node * n , int n) {

     struct node new;

  


     new.i = i;

     new.next = n;

  


     return &amp;new;

}

  


Typedef

     Provide a new name for an existing data type.

  


     typedef &lt;real type&gt; &lt;new name&gt;;

  


     ex:

          typedef unsigned long size_t;

          size_t x = 139;

  


     typedef struct foo { int a ; char x ;} bar;

          Here, bar is a typedef for struct {int a; char x;}

  


     bar s;

  


gdb (GNU Debugger)

  


     Allows you to get detailed information about a program while it is running.
