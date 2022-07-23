cache-test: cache-test.cc cache.o lru.o hashtable.o
	g++ -ggdb cache-test.cc cache.o lru.o hashtable.o -o cache-test
cache.o: cache.cc cache.h hashtable.o policy.h
	g++ -c cache.cc
lru.o: lru.cc lru.h node.h policy.h
	g++ -c lru.cc
hashtable.o: hashtable.cc hashtable.h
	g++ -c hashtable.cc
clean:
	rm *.o cache-test