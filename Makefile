.PHONY: clean All

All:
	@echo "----------Building project:[ 22-5-blinker -  ]----------"
	@cd "22-5-blinker" && "$(MAKE)" -f  "22-5-blinker.mk"
clean:
	@echo "----------Cleaning project:[ 22-5-blinker -  ]----------"
	@cd "22-5-blinker" && "$(MAKE)" -f  "22-5-blinker.mk" clean
