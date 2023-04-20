from os import system, path
import sys
import pathlib

C_COMPILER = "gcc"


def main():
    # Get C files
    src = pathlib.Path("./src/")
    files = [str(i) for i in src.rglob("*.c") if i.is_file()]

    # Start Build
    print("🚧 Building...")
    if not path.exists("./bin/"):
        system("mkdir bin")
    err = system(f"{C_COMPILER} {' '.join(files)} -o ./bin/a.exe")

    if not err:
        print("✅ Build completed without errors!")
    else:
        print("❌ Errors encountered, build not completed!")
        exit(-1)

    if len(sys.argv) == 2 and sys.argv[1] == "run":
        print("\n⚙️ Running...\n")
        err = system(f".\\bin\\a.exe")
        if not err:
            print("\n✅ Run complete without errors!")
        else:
            print("\n❌ Errors encountered while running")
            exit(-2)


if __name__ == "__main__":
    main()
