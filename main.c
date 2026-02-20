#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    TYPE_FLOAT32,
    TYPE_INT8
} DataType;

typedef union {
    float f32;
    int8_t i8;
} TensorData;

typedef struct {
    TensorData *data;
    uint32_t size;
    DataType type;
} Tensor;

void quantize(float value, int8_t *target) {
    *target = (int8_t)value; 
}

int main() {
    uint32_t element_count = 5;
    uint32_t i; 
    float sample_data[] = {74.8, 12.9, 7.6, 23.3, 9.0};
    Tensor myTensor;

    myTensor.size = element_count;
    myTensor.type = TYPE_FLOAT32;
    myTensor.data = (TensorData*)malloc(element_count * sizeof(TensorData));

    printf("--- FLOAT32 MODU ---\n");
    for(i = 0; i < element_count; i++) { 
        myTensor.data[i].f32 = sample_data[i];
        printf("Veri %u: %.2f\n", i, myTensor.data[i].f32);
    }

    printf("\n--- INT8 MODUNA GECIS ---\n");
    myTensor.type = TYPE_INT8;
    for(i = 0; i < element_count; i++) {
        int8_t q_val;
        quantize(sample_data[i], &q_val);
        myTensor.data[i].i8 = q_val;
        printf("Veri %u: %d\n", i, myTensor.data[i].i8);
    }

    free(myTensor.data);
    return 0;
}
