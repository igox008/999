#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <git_add_arguments> <commit_message> <git_push_arguments>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *gitAddCmd = "git add ";
    const char *gitCommitCmd = "git commit -m ";
    const char *gitPushCmd = "git push ";

    char gitCmd[256];

    strcpy(gitCmd, gitAddCmd);
    strcat(gitCmd, argv[1]);

    system(gitCmd);

    strcpy(gitCmd, gitCommitCmd);
    strcat(gitCmd, "\"");
    strcat(gitCmd, argv[2]);
    strcat(gitCmd, "\"");

    system(gitCmd);

    strcpy(gitCmd, gitPushCmd);
    strcat(gitCmd, argv[3]);

    system(gitCmd);

    return EXIT_SUCCESS;
}
