from os import system
import sys
import pathlib

C_COMPILER = "gcc"


def main():
    # Get C files
    src = pathlib.Path("./src/")
    files = [str(i) for i in src.rglob("*.c") if i.is_file()]

    # Start Build
    print("🚧 Building...")
    err = system(f"{C_COMPILER} {' '.join(files)} -o ./bin/a.exe")

    if not err:
        print("✅ Build completed without errors!")
    else:
        print("❌ Errors encountered, build not completed!")

    if len(sys.argv) == 2 and sys.argv[1] == "run":
        print("\n⚙️ Running...\n")
        err = system(f".\\bin\\a.exe")
        if not err:
            print("\n✅ Run complete without errors!")
        else:
            print("\n❌ Errors encountered while running")


if __name__ == "__main__":
    main()
