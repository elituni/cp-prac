import random
import subprocess
import tempfile
import os

# ---------------- BRUTE FORCE CHECK ----------------
def is_valid(a):
    if len(a) == 1:
        return True
    total = sum(a)
    if total % 2 != 0:
        return False
    prefix = 0
    for i in range(len(a) - 1):
        prefix += a[i]
        if prefix * 2 == total:
            if is_valid(a[:i+1]) and is_valid(a[i+1:]):
                return True
    return False


# ---------------- TEST GENERATOR ----------------
def gen_test_case(max_n=8, max_pow=4):
    n = random.randint(1, max_n)
    arr = [2 ** random.randint(0, max_pow) for _ in range(n)]
    return arr


# ---------------- COMPARE WITH C++ ----------------
def run_cpp_on_input(input_str):
    with tempfile.NamedTemporaryFile(mode="w+", delete=False) as f:
        f.write(input_str)
        f.flush()
        result = subprocess.run(
            ["./a.out"], input=input_str, text=True, capture_output=True, timeout=2
        )
    return result.stdout.strip().splitlines()


# ---------------- MAIN TEST LOOP ----------------
def main():
    # Make sure your compiled C++ code is named a.out in the same directory
    for t in range(100):
        tcount = random.randint(1, 5)
        tests = []
        brute_ans = []
        input_str = f"{tcount}\n"
        for _ in range(tcount):
            arr = gen_test_case()
            input_str += f"{len(arr)}\n{' '.join(map(str, arr))}\n"
            brute_ans.append("YES" if is_valid(arr) else "NO")

        cpp_out = run_cpp_on_input(input_str)

        if [s.upper() for s in cpp_out] != [s.upper() for s in brute_ans]:
            print("❌ Mismatch found!")
            print("Input:\n", input_str)
            print("Expected:\n", "\n".join(brute_ans))
            print("Got:\n", "\n".join(cpp_out))
            break
    else:
        print("✅ All tests passed!")


if __name__ == "__main__":
    main()
