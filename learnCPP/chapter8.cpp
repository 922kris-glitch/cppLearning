/*
Chapter 8: Control flow and randomness
Bug museum. Write one tiny program per bug, run each, and predict the output before running it:
A dangling else with no braces. Feed it 21 and see which if the else attaches to.
if (x = 0).
if (cond); followed by a block.
A while(count < 10);.
Then fix each one with braces and compare.

Unsigned loop trap. Write a countdown with an unsigned counter and >= 0. Then run it once with a debugger or print cap so it doesn’t hang, and watch it wrap. Rewrite it with a signed counter. Do it again with size_t i = v.size() - 1 on an empty vector.

Switch lab.
Build a calculator switch, then delete the breaks and see the fallthrough.
Add [[fallthrough]] on purpose.
Make an isVowel with stacked labels.
Try to initialize a variable inside a case without braces, read the compiler error, then fix it with braces.
Define a variable in case 1, jump straight to case 2, and read it (sanitizers or warnings should object).

for loop order of evaluation. Give each part of a for a function that prints which part ran (init, condition, body, end-expression). Run it and confirm the order. Then do the same with continue in the body to prove the end-expression still runs. Repeat with a while plus continue and see the hang.

!= vs < in a loop. Write the loop that skips over 10 with ++i inside the body and compare the two conditions (cap the iterations so the != version terminates).

break only exits the innermost loop. Search a 2D grid for a value with nested loops. First use a flag, then a break plus flag, then a helper function that returns early. Compare which reads best.

std::exit vs return. Make a small class whose constructor and destructor print messages. Create one in main and one static global. Exit via return, then via std::exit(0) from a nested function, then via std::abort(). Note which destructors ran each time. Add two std::atexit handlers and confirm they run in reverse order.

Randomness. Build a function that uses std::mt19937 seeded once with random_device, plus a uniform distribution. Then write the two bugs deliberately and see them:
The engine constructed (and seeded) inside the function that’s called in a loop.
A default-seeded engine, run twice, to confirm the identical sequence.
Then fix them. Finish with a fixed seed so a failing run is reproducible, and a histogram of 100,000 rolls of a six-sided die to check it’s roughly uniform.
*/