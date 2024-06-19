class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()
        for email in emails:
            local_name, domain_name = email.split('@')
            unique_emails.add((
                self._normalize_local_name(local_name),
                domain_name,
            ))
        return len(unique_emails)

    def _normalize_local_name(self, local_name):
        return self._remove_all_dots(self._remove_plus_and_after(local_name))

    def _remove_all_dots(self, text):
        return text.replace('.', '')

    def _remove_plus_and_after(self, text):
        return text.split('+')[0]
