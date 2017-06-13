.PHONY: clean All

All:
	@echo "----------Building project:[ practice - Debug ]----------"
	@cd "practice" && "$(MAKE)" -f  "practice.mk"
clean:
	@echo "----------Cleaning project:[ practice - Debug ]----------"
	@cd "practice" && "$(MAKE)" -f  "practice.mk" clean
