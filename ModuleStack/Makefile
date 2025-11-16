
.PHONY: all clean test-static test-dinamic test-benchMarkDynamico test-banchMarkStatic

all:  test-dinamic test-static

test-static: programaStatic 
	./programaStatic

test-dinamic: programaDinamic 
	./programaDinamic

test-benchMarkDynamico: banchMarkDynamic
	./banchMarkDynamic

test-banchMarkStatic: banchMarkContiguousStatic
	./banchMarkStatic

banchMarkContiguousStatic: StackModuleContiguousStatic.c banchMarkContiguousStatic.c
	gcc StackModuleContiguousStatic.c banchMarkContiguousStatic.c -o banchMarkStatic

banchMarkDynamic: StackModuleLinkedDynamic.c banchMarkLinkedDynamic.c
	gcc StackModuleLinkedDynamic.c banchMarkLinkedDynamic.c -o banchMarkDynamic

programaStatic : StackModuleContiguousStatic.c
	gcc StackModuleContiguousStatic.c StackModuleTest.c -o programaStatic

programaDinamic: StackModuleLinkedDynamic.c
	gcc StackModuleLinkedDynamic.c StackModuleTest.c -o programaDinamic

clean : 
	rm -f programaStatic programaDinamic banchMarkDynamic banchMarkStatic