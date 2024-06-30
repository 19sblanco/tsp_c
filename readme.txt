Traveling salesman problem implimented in C using as few libraries as possible

I'm optimizing my code and storing the different versions as git branches. Each subsequent version is it's earlier versions plus some feature. Here is my work so far:
* main - tsp using backtracking and heavy use of heap memory
* v2.0 - converted all heap memory to the stack which resulted in almost 2 times speed up in some cases
* v3.0 - (not yet finished) I will stop searching down a path if that path is longer than the current best path

