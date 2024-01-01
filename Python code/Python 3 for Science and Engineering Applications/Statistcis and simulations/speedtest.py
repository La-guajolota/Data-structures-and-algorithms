import time
import random
import statistics as stats

def speedtest(functions, n):

    assert isinstance(functions, list)
    times = {f: [] for f in functions}

    for run in range(n):
        random.shuffle(functions)

        for function in functions:
            start_time = time.monotonic()
            function()
            end_time = time.monotonic()
            times[function].append(end_time - start_time)

    for function, runtime in times.items():
        print(f"{function}: {stats.mean(runtime):.4f} | \
        {stats.median(runtime):.4f}")