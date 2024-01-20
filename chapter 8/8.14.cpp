//Exercise 8.14: Why did we declare entry and nums as const auto &?

/*
 * Answer:
 * We did so in order to prevent making a copy of entry and nums each iteration and to make sure that the object itself
 * doesn't change.
 */
