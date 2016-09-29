.PHONY: main
main:
	make -C src $@
	cp src/$@ $@

.PHONY: clean
clean:
	make -C src $@
	rm -f main
