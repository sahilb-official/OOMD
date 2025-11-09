// FileName: Enums.h
#pragma once

// Represents the lifecycle status of a product
enum class ProductStatus {
    AWAITING_APPROVAL,
    AVAILABLE,
    SOLD,
    DONATED
};

// Represents the status of a transaction
enum class TransactionStatus {
    PENDING,
    COMPLETED,
    FAILED
};