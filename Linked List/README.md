# Linked List in C with Unit Tests

這是一個使用 C 語言實作的 linked list和 作為內部儲存方式，並以 CUnit 撰寫基本單元測試。

## 專案結構

```bash
.
└── Single_liniked_list/
│   ├── include/                 # 標頭檔
│   │   └── Single_Linked_list.h
│   │   └── Single_Linked_List_dump.h
│   ├── src/                    # 程式實作
│   │   └── Single_Linked_list.c
│   │   └── Single_Linked_List_dump.c
│   ├── test/                   # 測試檔案
│   │   └── test.c
│   ├── Makefile                
│   └── README.md
│
└── Doubly_liniked_list/
    ├── include/                 # 標頭檔
    │   └── Doubly_Linked_List.h
    ├── src/                    # 程式實作
    │   └── Doubly_Linked_List.c
    ├── test/                   # 測試檔案
    │   └── test.c
    ├── Makefile                
    └── README.md   
```

## 安裝 CUnit
```bash
sudo apt update
sudo apt install libcunit1-dev
```

## 建置專案
```bash
make
```

## 執行test case
```bash
./testexe
```

## GitHub Actions CI 支援
已配置 .github/workflows/ci.yml，當你推送程式到 GitHub 時，會自動進行建置與測試。