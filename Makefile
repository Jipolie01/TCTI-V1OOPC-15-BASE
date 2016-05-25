.PHONY: clean All

All:
	@echo "----------Building project:[ 15-10-bounce -  ]----------"
	@cd "15-10-bounce" && "$(MAKE)" -f  "15-10-bounce.mk"
clean:
	@echo "----------Cleaning project:[ 15-10-bounce -  ]----------"
	@cd "15-10-bounce" && "$(MAKE)" -f  "15-10-bounce.mk" clean
