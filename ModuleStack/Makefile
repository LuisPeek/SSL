 


.PHONY: all clean

run: programaStatic 
	./programaStatic


test-static: programaStatic 
	./programaStatic

test-dinamic: programaDinamic 
	./programaDinamic


programaStatic : StackModuleContiguousStatic.c
	gcc StackModuleContiguousStatic.c StackModuleTest.c -o programaStatic

programaDinamic: StackModuleLinkedDynamic.c
	gcc StackModuleLinkedDynamic.c StackModuleTest.c -o programaDinamic


clean : 
	rm -f programaStatic programaDinamic