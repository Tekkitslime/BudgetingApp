#include <stdio.h>
#include <string.h>
#include <time.h>
#include "raylib.h"

#define MAX_BANK_ACCOUNTS 64
#define MAX_BANK_ACCOUNT_NAME 64
#define MAX_TRANSACTIONS 1<<16

typedef struct Bank_Account {
	char name[MAX_BANK_ACCOUNT_NAME];
	int money;
} Bank_Account;

typedef struct Transaction {
	int bank_account;
	int difference;
	time_t date_created;
} Transaction;

typedef struct Budget_Goal {
	bool onAccount;
	char *account_name;

	time_t date_created;

	int amount;
} Budget_Goal;

Bank_Account bank_accounts[MAX_BANK_ACCOUNTS] = {0};
int bank_accounts_len = 0;

Bank_Account *make_bank_account(char *name, int money) {
	if (strlen(name) >= MAX_BANK_ACCOUNT_NAME) return NULL;
	if (bank_accounts_len >= MAX_BANK_ACCOUNTS) return NULL;

	Bank_Account *account = &bank_accounts[bank_accounts_len];

	account->money = money;
	char *last = stpncpy(account->name, name, MAX_BANK_ACCOUNT_NAME-1);
	(*last) = 0;

	bank_accounts_len++;
	return account;
}

void delete_bank_account(Bank_Account *account) {
	if (bank_accounts_len <= 0) {
		bank_accounts_len = 0;
		return;
	}

	int index = account - bank_accounts;
	for (int i=index; i<bank_accounts_len; i++) {
		bank_accounts[i] = bank_accounts[i+1];
	}

	bank_accounts_len--;
}

int main() {
	make_bank_account("groceries", 10*100);
	make_bank_account("homeries", 20*100);
	make_bank_account("dodgeries", 30*100);
	for (int i=0; i<bank_accounts_len; i++)
		printf("bank_account(%s): %d\n", bank_accounts[i].name, bank_accounts[i].money);

	putchar('\n');

	delete_bank_account(&bank_accounts[3]);
	for (int i=0; i<bank_accounts_len; i++)
		printf("bank_account(%s): %d\n", bank_accounts[i].name, bank_accounts[i].money);

	return 0;
	InitWindow(800, 600, "Budgeting App");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Hello, world!", GetMouseX(), GetMouseY(), 16, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
