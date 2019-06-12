
extern unsigned char __heap_base;

const unsigned int wasm_page_size = 65536;
const unsigned int marker_value = 42;

int write_value_at(unsigned char *ref) {
    unsigned int current_memory = __builtin_wasm_memory_size(0);
    unsigned char *current_max = (unsigned char *)(current_memory * wasm_page_size);
    unsigned char *desired_max = ref + sizeof(marker_value);
    if (current_max < desired_max) {
        unsigned int target_memory = (((unsigned int)desired_max) + wasm_page_size - 1) / wasm_page_size;
        unsigned int delta = target_memory - current_memory;
        
        if (__builtin_wasm_memory_grow(0, delta) < 0) {
            return -1;
        }
    }

    *ref = 42;
    return 0;
}

